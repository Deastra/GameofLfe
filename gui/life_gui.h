#ifndef LFG
#define LFG

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <SDL.h>
#include "life.h"

#define SIZE 15

// Creating the SDL window and renderer 
// using passed arguments width and height
SDL_Renderer* Create_Window_Renderer(int width, int height);

// Creating SDL rectangle for displaying the colors 
// of the cells from the life-map
SDL_Rect SDL_Create_Rect ();

// Updating the position of the rectangle
// as passes through the whole window for each cell
void Rect_Update(SDL_Rect* rect,int x, int y);

// Coloring the cells from the map based on its ( cell's ) state
// Black for deads, Golden for alives
void Game_Render(int **map, SDL_Renderer *ren,SDL_Rect *rect);

// Initializing the window and the map so the life can start
// and continue on a endless loop untill everybody is dead...
// version=1:: circular-neighboors version
// else:: direct-neighboors version
int Game(int version);

#endif
