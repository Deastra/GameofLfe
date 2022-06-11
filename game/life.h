#ifndef LIFE
#define LIFE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#define SIZE 15

// Reseting the print color of ansicode
void reset();

// Dynamically allocating the 2D array for 
// the main map of the life and filling it with
// "dead" cells
int** initiateMap();

// Displaying the map of life using ansicode drawing
// Green for alive members and red for dead ones
void printMap(int** map);

// Initializing the first day of life
// by randomizing the each cell for being
// alive or dead, just for one day...
int** firstDay();

// Returns 0 if all the cells on the
// board are dead and life is stopped :(
int ifAllDead(int** map);

// Two versions for neighboor count as specified in the protocol
// -----------------------------------------------------
// Counting neighboors for circular version of the game
int countNeighborsCircular(int **map,int x,int y);

// Counting neighboors for direct version of the game
int countNeighbors(int** map,int x, int y);

// Getting the next state of the cell
// In context of it being it dead or alive
int getNextState(int** map,int x,int y,int cf);

// Creating a new map of life using the properties
// of the last day for each sell from the previous map
int** nextDay(int** map,int cf);

// Console version of the program using ansicode drawing
int** lifeDay(int cf,int **maps);

#endif