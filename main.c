#include <stdio.h>
#include "src/debugmalloc.h"
#include "src/map.h"
#include "src/movement.h"
#include <windows.h>

int main() {
    SetConsoleOutputCP(65001);
    char** map = initMap();
    printMap(map);
    MovData movementData = Empty;
    int lootCounter = 0;

    while(movementData != Exit){
        //clearStdIn();
        Dir movementDir;
        switch (tolower(getchar())) {
            case 'w':
                movementDir = W;
                break;
            case 'a':
                movementDir = A;
                break;
            case 's':
                movementDir = S;
                break;
            case 'd':
                movementDir = D;
                break;
            default:
                movementDir = Default;
                break;
        }
        if(movementDir == Default) {
            printf("Lehetséges irányok: W A S D\n");
            continue;
        }
        movementData = advancePlayer(map, movementDir);
        if(movementData == Wall) {
            printf("Nem mehetsz abba az irányba!\n");
            continue;
        }
        if(movementData == Loot)
            lootCounter++;
        system("cls");
        printMap(map);
    }

    if(lootCounter < numOfLoot(map)){
        printf("Nem találtad meg az összes kincset, vesztettél! (nyomj meg akármit a kilépéshez)\n");
    } else{
        printf("Megtaláltad az összes kincset, nyertél! (nyomj meg akármit a kilépéshez)\n");
    }
    freeMap(map);
    while ( getchar() != '\n' ); //stdIn kitakarítás
    getchar(); //látszódjon a kilépő üzenet
    return 0;
}
