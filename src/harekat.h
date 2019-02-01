//
// Created by majid on 12/23/2018.
//

#ifndef PROJECT_HAREKAT_H
#define PROJECT_HAREKAT_H

#include "structha.h"
//void voroodnomre(bool a[]);
int cheksar(Map map, double x, double y, double r);
int savefeshar();
int savejra();
int menu();
void klid(double snake_radius,tanks tank[],int *flagtir,int step,Map map,int *flagtir2,int *s,int *ss,int *lazerbezan1,int *lazerbezan2);
int handleEvents();
int salam();

#endif //PROJECT_HAREKAT_H
