//
// Created by majid on 12/23/2018.
//

#ifndef PROJECT_NAGHSHEHA_H
#define PROJECT_NAGHSHEHA_H

#include "structha.h"
int min(double a, double b);
int max(double a, double b);
void khoondan(Map *map);
void rasm(Map *map,SDL_Renderer *renderer);
int divarkhor(Map map, double x, double y,double_t r);
int saresh(int x,int y,int x2,int y2,Map map);
void maprand(int shomare,box khoone[][5][5]);
int aval(box khoone[][5][5],Map *map, double tool, double arz);
void rasja(box khoone[][5][5],SDL_Renderer *renderer,Map *map,double tool, double arz);
void dfs(int x,int y,box khoone[][5][5],int mark[][5],int shomare);
void dor(int sho,box khoone[][5][5]);

#endif //PROJECT_NAGHSHEHA_H
