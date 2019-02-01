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
void rasmap(SDL_Renderer *renderer,Map map){
    for(int i=0;i<map.tedad;i++){
        thickLineRGBA(renderer,map.divar[i].x1,map.divar[i].y1,map.divar[i].x2,map.divar[i].y2,2,80,80,80,255);
    }
}
void rasmenu(SDL_Renderer *renderer,int n,int a){
    if(a==2) {
        if (n == 1) {
            thickLineRGBA(renderer, 250, 0, 500, 0, 20, 144, 144, 144, 255);
            thickLineRGBA(renderer, 250, 20, 500, 20, 20, 211, 211, 211, 255);
            thickLineRGBA(renderer, 250, 40, 500, 40, 20, 211, 211, 211, 255);
            thickLineRGBA(renderer, 250, 60, 500, 60, 20, 211, 211, 211, 255);
        }
        if (n == 2) {
            thickLineRGBA(renderer, 250, 0, 500, 0, 20, 211, 211, 211, 255);
            thickLineRGBA(renderer, 250, 20, 500, 20, 20, 144, 144, 144, 255);
            thickLineRGBA(renderer, 250, 40, 500, 40, 20, 211, 211, 211, 255);
            thickLineRGBA(renderer, 250, 60, 500, 60, 20, 211, 211, 211, 255);
        }
        if (n == 3) {
            thickLineRGBA(renderer, 250, 0, 500, 0, 20, 211, 211, 211, 255);
            thickLineRGBA(renderer, 250, 20, 500, 20, 20, 211, 211, 211, 255);
            thickLineRGBA(renderer, 250, 40, 500, 40, 20, 144, 144, 144, 255);
            thickLineRGBA(renderer, 250, 60, 500, 60, 20, 211, 211, 211, 255);
        }
        if (n == 4) {
            thickLineRGBA(renderer, 250, 0, 500, 0, 20, 211, 211, 211, 211);
            thickLineRGBA(renderer, 250, 20, 500, 20, 20, 211, 211, 211, 255);
            thickLineRGBA(renderer, 250, 40, 500, 40, 20, 211, 211, 211, 255);
            thickLineRGBA(renderer, 250, 60, 500, 60, 20, 144, 144, 144, 255);
        }
        stringRGBA(renderer, 250, 0, "save", 0, 0, 0, 255);
        stringRGBA(renderer, 250, 20, "edame", 0, 0, 0, 255);
        stringRGBA(renderer, 250, 40, "load", 0, 0, 0, 255);
        stringRGBA(renderer, 250, 60, "khorooj", 0, 0, 0, 255);
    }
    if(a==1){
//        if (n == 1) {
//            thickLineRGBA(renderer, 250, 0, 500, 0, 20, 144, 144, 144, 255);
//            thickLineRGBA(renderer, 250, 20, 500, 20, 20, 211, 211, 211, 255);
//            thickLineRGBA(renderer, 250, 40, 500, 40, 20, 211, 211, 211, 255);
//            thickLineRGBA(renderer, 250, 60, 500, 60, 20, 211, 211, 211, 255);
//        }
        if (n == 2) {
            //thickLineRGBA(renderer, 250, 0, 500, 0, 20, 211, 211, 211, 255);
            thickLineRGBA(renderer, 250, 0, 500, 0, 20, 144, 144, 144, 255);
            thickLineRGBA(renderer, 250, 20, 500, 20, 20, 211, 211, 211, 255);
            thickLineRGBA(renderer, 250, 40, 500, 40, 20, 211, 211, 211, 255);
        }
        if (n == 3) {
            //thickLineRGBA(renderer, 250, 0, 500, 0, 20, 211, 211, 211, 255);
            thickLineRGBA(renderer, 250, 0, 500, 0,20, 211, 211, 211, 255);
            thickLineRGBA(renderer, 250, 20, 500, 20, 20, 144, 144, 144, 255);
            thickLineRGBA(renderer, 250, 40, 500, 40, 20, 211, 211, 211, 255);
        }
        if (n == 4) {
            //thickLineRGBA(renderer, 250, 0, 500, 0, 20, 211, 211, 211, 211);
            thickLineRGBA(renderer, 250, 0, 500, 0,20, 211, 211, 211, 255);
            thickLineRGBA(renderer, 250, 20, 500, 20, 20, 211, 211, 211, 255);
            thickLineRGBA(renderer, 250, 40, 500, 40, 20, 144, 144, 144, 255);
        }
       // stringRGBA(renderer, 250, 0, "save", 0, 0, 0, 255);
        stringRGBA(renderer, 250, 0, "edame", 0, 0, 0, 255);
        stringRGBA(renderer, 250, 20, "load", 0, 0, 0, 255);
        stringRGBA(renderer, 250, 40, "khorooj", 0, 0, 0, 255);
    }

}

void rasmtir(double snake_radius,tanks tank[],SDL_Renderer *renderer,int step,Map map){
    double rt= snake_radius / 4;
    for(int j=1;j<3;j++) {
        for (int i = 0; i < 15; i++) {
            if (i<5&&tank[j].tir[i].por == true) {
                if (divarkhor(map, tank[j].tir[i].x + step * cos(tank[j].tir[i].zavtir), tank[j].tir[i].y - step * sin(tank[j].tir[i].zavtir),snake_radius / 4) == 2) {
                    tank[j].tir[i].zavtir = -tank[j].tir[i].zavtir;
                } else if (divarkhor(map, tank[j].tir[i].x + step * cos(tank[j].tir[i].zavtir), tank[j].tir[i].y - step * sin(tank[j].tir[i].zavtir),snake_radius / 4) == 1) {
                    tank[j].tir[i].zavtir = -tank[j].tir[i].zavtir - M_PI;
                }
                tank[j].tir[i].y -= step * sin(tank[j].tir[i].zavtir);
                tank[j].tir[i].x += step * cos(tank[j].tir[i].zavtir);
                filledCircleRGBA(renderer, tank[j].tir[i].x, tank[j].tir[i].y, snake_radius / 4, 0, 100, 100, 255);
                tank[j].tir[i].zaman++;
            }
            if (i==5&&tank[j].tir[i].por == true){
                if (divarkhor(map, tank[j].tir[i].x + step * cos(tank[j].tir[i].zavtir), tank[j].tir[i].y - step * sin(tank[j].tir[i].zavtir),snake_radius / 4) == 2) {
                    tank[j].tir[i].zavtir = -tank[j].tir[i].zavtir;
                } else if (divarkhor(map, tank[j].tir[i].x + step * cos(tank[j].tir[i].zavtir), tank[j].tir[i].y - step * sin(tank[j].tir[i].zavtir),snake_radius / 4) == 1) {
                    tank[j].tir[i].zavtir = -tank[j].tir[i].zavtir - M_PI;
                }
                tank[j].tir[i].y -= step * sin(tank[j].tir[i].zavtir);
                tank[j].tir[i].x += step * cos(tank[j].tir[i].zavtir);
                filledCircleRGBA(renderer, tank[j].tir[i].x, tank[j].tir[i].y, snake_radius / 4+4, 0, 100, 100, 255);
                tank[j].tir[i].zaman++;
            }
            if (i>5&&tank[j].tir[i].por == true) {
                step+=1;
                if (divarkhor(map, tank[j].tir[i].x + step* cos(tank[j].tir[i].zavtir), tank[j].tir[i].y - step * sin(tank[j].tir[i].zavtir),snake_radius / 4) == 2) {
                    tank[j].tir[i].por=false;
                   // filledCircleRGBA(renderer, tank[j].tir[i].x, tank[j].tir[i].y, snake_radius / 4-1, 0, 100, 100, 255);
                }
                else if (divarkhor(map, tank[j].tir[i].x + step * cos(tank[j].tir[i].zavtir), tank[j].tir[i].y - step * sin(tank[j].tir[i].zavtir),snake_radius / 4) == 1) {
                    tank[j].tir[i].por=false;
                    //filledCircleRGBA(renderer, tank[j].tir[i].x, tank[j].tir[i].y, snake_radius / 4-1, 0, 100, 100, 255);
                }
                else {
                    tank[j].tir[i].y -= step * sin(tank[j].tir[i].zavtir);
                    tank[j].tir[i].x += step * cos(tank[j].tir[i].zavtir);
                    filledCircleRGBA(renderer, tank[j].tir[i].x, tank[j].tir[i].y, snake_radius / 4-1, 0, 100, 100, 255);
                    tank[j].tir[i].zaman++;
                }
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
void jaselah(selahs *sela,double tool,double arz){
    int shomare=rand()%4+1;
    double x=rand()%5;
    double y=rand()%5;
    double jb=(750-tool)/2;
    if(shomare==1){
        sela->x=jb+x*tool/10+tool/20;
        sela->y=y*arz/10+arz/20;
    }
    if(shomare==2){
        sela->x=jb+x*tool/10+tool/20+tool/2;
        sela->y=y*arz/10+arz/20;
    }
    if(shomare==3){
        sela->x=jb+x*tool/10+tool/20;
        sela->y=y*arz/10+arz/20+arz/2;
    }
    if(shomare==4){
        sela->x=jb+x*tool/10+tool/20+tool/2;
        sela->y=y*arz/10+arz/20+arz/2;
    }
}