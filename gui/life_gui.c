#include "life_gui.h"

int height=600;
int width=600;
int next=600/15;


SDL_Renderer* Create_Window_Renderer(int width, int height){
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window * win = SDL_CreateWindow(
        "Game of Life",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        width,
        height,
        SDL_WINDOW_SHOWN
    );
    
    if(win==NULL){printf("%s",SDL_GetError());}
    SDL_Renderer * ren = SDL_CreateRenderer(
    win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    return ren;

}

SDL_Rect SDL_Create_Rect (){
    SDL_Rect rect={
        .x=0,
        .y = 0,
        .w = 60,
        .h = 60
    };
    
    return rect;
}

void Rect_Update(SDL_Rect* rect,int x, int y){
    (*rect).x=x;
    (*rect).y=y;
}

void Game_Render(int **map,SDL_Renderer *ren,SDL_Rect *rect){
    
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if(map[i][j]==0){SDL_SetRenderDrawColor(ren, 0, 0, 0, 0);}
            else{SDL_SetRenderDrawColor(ren, 255, 215, 0, 0);}
            Rect_Update(rect,i*next,j*next);
            SDL_RenderFillRect(ren, rect);
        }
    }
        
}

int Game(int version) {

    SDL_Renderer* ren=Create_Window_Renderer(600,600);

    SDL_Rect rect=SDL_Create_Rect();

    SDL_Event event;

    bool running = true;

    int** map=firstDay();

    while (running) {
        
        SDL_SetRenderDrawColor(ren, 0, 0, 0, 0);
        SDL_RenderClear(ren);
        Game_Render(map,ren,&rect);
        if ((SDL_PollEvent(&event) && event.type == SDL_QUIT) || ifAllDead(map)) {running = false;}
        map=nextDay(map,version);
        sleep(1);

        SDL_RenderPresent(ren);
    }

    return 0;
}