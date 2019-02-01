//
// Created by majid on 1/20/2019.
//

#ifndef PROJECT_SAVEHA_H
#define PROJECT_SAVEHA_H
#include "structha.h"
void savekon(ssave save[],Map map,tanks tank[],int nomreh1,int nomreh2);
void jabejayi(ssave save[],Map *map,tanks tank[],int *n1,int *n2);
void klidmenu(int *flagup,int *flagdan,int *n,int a);
void savina(int *flagasli,int *n,int *t,ssave saveha[],Map *map,tanks tank[],int *tank1score,int *tank2score,selahs *selah);
void lazereshoon(SDL_Renderer *renderer,double x,double y,int tool,int arz,double zav);
void bekash(SDL_Renderer *renderer,double x,double y,double zav,int arz,int tool,tanks tank[],int r);
int saveakhar(Map map,tanks tank[],int s1,int s2,selahs selah);
void bekhoonesh(Map *map,tanks tank[],int *s1,int *s2,selahs *selah);
#endif //PROJECT_SAVEHA_H
