#ifndef LFG
#define LFG

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include "life.h"

#define SIZE 15


SDL_Renderer* Create_Window_Renderer(int width, int height);
SDL_Rect* SDL_Create_Rect ();
void Rect_Update(SDL_Rect* rect,int x, int y);
void Game_Render(int **map,SDL_Renderer *ren,SDL_Rect *rect);
int Game(int version);

#endif