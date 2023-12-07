//
// Created by balazs on 12/7/2023.
//

#include "map.h"
char** initMap(){
    FILE* input = fopen("map.txt", "r");
    if(input == NULL){
        printf("Nincs meg a file!\n");
        exit(1);
    }
    char** map = malloc(sizeof(char*)*10);
        if(map == NULL){
            printf("Nem sikerült az allokáció %s %d\n",__FILE__, __LINE__);
            exit(1);
        }
    for(int i = 0; i<10; i++)
        map[i] = malloc(sizeof(char)*12);
    char buf[12];
    int c = 0;
    while(fgets(buf, 12, input) != NULL){
        strcpy(map[c++], buf);
    }
    fclose(input);
    return map;
}
void printMap(char** map){
    for(int i = 0; i<10; i++){
        printf("%s", map[i]);
    }
    putchar('\n');
}
void freeMap(char** map){
for(int i = 0; i<10; i++)
    free(map[i]);
free(map);
}
Coords getCoords(char** map){
    Coords coords = {.x = -1, .y = -1};
    for(int i = 0; i<10; i++){ //y
        for(int j = 0; j<10; j++){ //nem kell 10-nél tovább, mert 11 és 12 csak \n és \0 karakter
            if(map[i][j] == '@'){
                coords.y = i;
                coords.x = j;
            }
        }
    }
    return coords;
}
int numOfLoot(char** map){
    int counter = 0;
    for(int i = 0; i<10; i++){
        for(int j = 0; j<10; j++){
            if(map[i][j] == '$')
                counter++;
        }
    }
    return counter;
}
