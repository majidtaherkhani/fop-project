//
// Created by majid on 12/23/2018.
//

#ifndef PROJECT_NAGHSHEHA_H
#define PROJECT_NAGHSHEHA_H

#include "structha.h"

void khoondan(Map *map);
void rasm(Map *map,SDL_Renderer *renderer);
int divarkhor(Map map,int x,int y,int r);
int saresh(int x,int y,int x2,int y2,Map map);
void maprand(int shomare,box khoone[][5][5]);
int aval(box khoone[][5][5],Map *map);
void rasja(box khoone[][5][5],SDL_Renderer *renderer,Map *map);
void dfs(int x,int y,box khoone[][5][5],int mark[][5],int shomare);

#endif //PROJECT_NAGHSHEHA_H
