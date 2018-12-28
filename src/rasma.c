//
// Created by majid on 12/23/2018.
//
#include <stdio.h>
#include <stdlib.h>
#include "rasma.h"
#include "structha.h"
#include <SDL2_gfxPrimitives.h>
#include "naghsheha.h"
#include <time.h>
void rasmtir(double snake_radius,tanks tank[],SDL_Renderer *renderer,int step,Map map){
    double rt= snake_radius / 4;
    for(int j=1;j<3;j++) {
        for (int i = 0; i < 5; i++) {
            if (tank[j].tir[i].por == true) {
                if (divarkhor(map, tank[j].tir[i].x + step * cos(tank[j].tir[i].zavtir), tank[j].tir[i].y - step * sin(tank[j].tir[i].zavtir),snake_radius / 4) == 2) {
                    tank[j].tir[i].zavtir = -tank[j].tir[i].zavtir;
                } else if (divarkhor(map, tank[j].tir[i].x + step * cos(tank[j].tir[i].zavtir), tank[j].tir[i].y - step * sin(tank[j].tir[i].zavtir),snake_radius / 4) == 1) {
                    tank[j].tir[i].zavtir = -tank[j].tir[i].zavtir - M_PI;
                }
                tank[j].tir[i].y -= step * sin(tank[j].tir[i].zavtir);
                tank[j].tir[i].x += step * cos(tank[j].tir[i].zavtir);
                filledCircleRGBA(renderer, tank[j].tir[i].x, tank[j].tir[i].y, snake_radius / 4, 0, 100, 100, 255);tank[j].tir[i].zaman++;
            }
        }
    }
}
jatank(int adad ,tanks tank[], double tool, double arz){
    int shomare=rand()%4+1;
    double x=rand()%5;
    double y=rand()%5;
    double jb=(750-tool)/2;
    if(shomare==1){
        tank[adad].x=jb+x*tool/10+tool/20;
        tank[adad].y=y*arz/10+arz/20;
    }
    if(shomare==2){
        tank[adad].x=jb+x*tool/10+tool/20+tool/2;
        tank[adad].y=y*arz/10+arz/20;
    }
    if(shomare==3){
        tank[adad].x=jb+x*tool/10+tool/20;
        tank[adad].y=y*arz/10+arz/20+arz/2;
    }
    if(shomare==4){
        tank[adad].x=jb+x*tool/10+tool/20+tool/2;
        tank[adad].y=y*arz/10+arz/20+arz/2;
    }
}