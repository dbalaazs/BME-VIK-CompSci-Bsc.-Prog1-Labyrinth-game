//
// Created by balazs on 12/7/2023.
//

#ifndef LABOR1207_MAP_H
#define LABOR1207_MAP_H
#include "debugmalloc.h"
typedef struct Coords{
    int x,y;
} Coords;
char** initMap();
void printMap(char** map);
void freeMap(char** map);
Coords getCoords(char** map);
int numOfLoot(char** map);
#endif //LABOR1207_MAP_H
