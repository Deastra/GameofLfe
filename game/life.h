#ifndef LIFE
#define LIFE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#define SIZE 15

void reset();
int** initiateMap();
void printMap(int** map);
int** firstDay();
int ifAllDead(int** map);
int countNeighborsCircular(int **map,int x,int y);
int countNeighbors(int** map,int x, int y);
int getNextState(int** map,int x,int y,int cf);
int** nextDay(int** map,int cf);
int** lifeDay(int cf,int **maps);


#endif