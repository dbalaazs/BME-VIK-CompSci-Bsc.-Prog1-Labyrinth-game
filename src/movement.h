//
// Created by balazs on 12/7/2023.
//

#ifndef LABOR1207_MOVEMENT_H
#define LABOR1207_MOVEMENT_H
#include <stdbool.h>
#include "map.h"
typedef enum Dir{
    W, A, S, D, Default
} Dir;
typedef enum MovData{
    Wall, Exit, Loot, Empty
} MovData;
bool isLegalDir(Dir dir, char** map);
MovData advancePlayer(char** map, Dir dir);
void clearStdIn (void);
#endif //LABOR1207_MOVEMENT_H
