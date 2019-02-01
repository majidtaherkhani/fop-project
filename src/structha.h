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
    bool laizer;
    bool lazerasli;
    tirs tir[15];
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
typedef struct{
    Map mapkomaki;
    tanks tankha[3];
    int nomre1;
    int nomre2;
}ssave;
typedef struct {
    double x;
    double y;
    int zaman;
    int has;
}selahs;
typedef struct {
    double x;
    double y;
    int zaman;
    int has;
}lazers;

#endif //PROJECT_STRUCTHA_H
