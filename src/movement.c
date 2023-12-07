//
// Created by balazs on 12/7/2023.
//

#include "movement.h"
bool isLegalDir(Dir dir, char** map){
    Coords c = getCoords(map);
    bool retVal = false;
    switch (dir) {
        case W:
            retVal = (map[c.y-1][c.x] == '#') ? false : true; //azért - mert a lejjebb levő sor magasabb indexű
            break;
        case A:
            retVal = (map[c.y][c.x-1] == '#') ? false : true;
            break;
        case S:
            retVal = (map[c.y+1][c.x] == '#') ? false : true;
            break;
        case D:
            retVal = (map[c.y][c.x+1] == '#') ? false : true;
            break;
    }
    return retVal;
}
MovData advancePlayer(char** map, Dir dir){
    if(!isLegalDir(dir, map)){
        return Wall;
    }
    Coords c = getCoords(map);
    map[c.y][c.x] = ' ';    //current pos = ' '
    switch(dir){    //get new coords
        case W:
            c.y -= 1;
            break;
        case A:
            c.x -= 1;
            break;
        case S:
            c.y += 1;
            break;
        case D:
            c.x += 1;
            break;
    }
    if(map[c.y][c.x] == '$'){
        map[c.y][c.x] = '@';
        return Loot;
    }
    if(c.y == 0 || c.y == 10 || c.x == 0 || c.x == 10) {    //end of map in any dir
        return Exit;
    }
    map[c.y][c.x] = '@';
    return Empty;
}