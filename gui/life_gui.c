#include "life_gui.h"

// dimensions of the SDL window
int height=600;
int width=600;
int next=600/15; // size of each cell on the SDL window


SDL_Renderer* Create_Window_Renderer(int width, int height){
    // SDL Window initializing
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window * win = SDL_CreateWindow( 
        "Game of Life",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        width,
        height,
        SDL_WINDOW_SHOWN
    );
    // Check window error
    if(win==NULL){printf("%s",SDL_GetError()); exit(-1);}
    // Initializing the window renderer
    SDL_Renderer * ren = SDL_CreateRenderer(
    win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    return ren;

}

SDL_Rect SDL_Create_Rect (){
    // Initializing the SDL rectangle for 
    // position 0 0 and width and height of the each cell
    SDL_Rect rect={
        .x=0,
        .y = 0,
        .w = next,
        .h = next
    };
    
    return rect;
}

void Rect_Update(SDL_Rect* rect,int x, int y){
    // Position update of rectangle
    (*rect).x=x;
    (*rect).y=y;
}

void Game_Render(int **map,SDL_Renderer *ren,SDL_Rect *rect){
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if(map[i][j]==0){SDL_SetRenderDrawColor(ren, 0, 0, 0, 0);}  // Color set for the dead cells to black
            else{SDL_SetRenderDrawColor(ren, 255, 215, 0, 0);} // Color set for the alive cells to golden
            Rect_Update(rect,i*next,j*next); // Rectangle position to the next cell
            SDL_RenderFillRect(ren, rect); // Coloring the current cell on the window 
        }
    }
        
}

int Game(int version) {

    SDL_Renderer* ren=Create_Window_Renderer(width,height); // Initializing the window and renderer

    SDL_Rect rect=SDL_Create_Rect(); // Initializing the rectangle for coloring the cells

    SDL_Event event; // Event handler 

    bool running = true;

    int** map=firstDay(); // Getting the map of first day of the life

    while (running) {
        
        SDL_SetRenderDrawColor(ren, 0, 0, 0, 0); // Setting the renderer as a default ( just in case )
        SDL_RenderClear(ren);

        Game_Render(map,ren,&rect); // Coloring the cells for current day
        if ((SDL_PollEvent(&event) && event.type == SDL_QUIT) || ifAllDead(map)) {running = false;} // Quit handling

        map=nextDay(map,version); // Get the map of the next day
        sleep(1); // Slowing down for observing

        SDL_RenderPresent(ren);
    }

    return 0;
}