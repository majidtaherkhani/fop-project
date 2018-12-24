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
    int x1;
    int x2;
    int y1;
    int y2;
}Divar;
typedef struct{
    Divar divar[50];
    int tedad;
}Map;

#endif //PROJECT_STRUCTHA_H
