//
// Created by majid on 12/23/2018.
//

#ifndef PROJECT_STRUCTHA_H
#define PROJECT_STRUCTHA_H

#include <stdbool.h>

typedef struct{
    double zavtir;
    double x;
    double y;
    bool por;
    int zaman;
} tirs;
typedef struct{
    double x;
    double y;
    double zav;
    tirs tir[5];
    bool has;
}tanks;
typedef struct {
    double x1;
    double x2;
    double y1;
    double y2;
}Divar;
typedef struct{
    Divar divar[200];
    int tedad;
}Map;
typedef struct{
    double x;
    double y;
    bool divup;
    bool divdon;
    bool divright;
    bool divleft;
}box;

#endif //PROJECT_STRUCTHA_H
