//
// Created by majid on 12/23/2018.
//
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <SDL.h>
#include <SDL2_gfxPrimitives.h>
#include "naghsheha.h"
#include "structha.h"


void khoondan(Map *map){
    FILE *file;
    file=fopen("C:\\Users\\majid\\Desktop\\majijjjj.txt","r");
    char khataval[20];
    fgets(khataval,20,file);
    map->tedad=(khataval[0]-'0')*10+khataval[1]-'0';
    for(int i=0; i< map->tedad ;i++){
        char khat[20];
        fgets(khat,20,file);
        map->divar[i].x1=(khat[0]-'0')*100;
        map->divar[i].y1=(khat[2]-'0')*100;
        map->divar[i].x2=(khat[4]-'0')*100;
        map->divar[i].y2=(khat[6]-'0')*100;
    }
}
void rasm(Map *map,SDL_Renderer *renderer){
    for(int i=0;i<map->tedad;i++){
        thickLineRGBA(renderer,map->divar[i].x1,map->divar[i].y1,map->divar[i].x2,map->divar[i].y2,5,0,0,0,255);
    }
}
int divarkhor(Map map,int x,int y,int r){
    for(int i=0;i<map.tedad;i++){
        if(map.divar[i].x1==map.divar[i].x2){
            if(map.divar[i].y1>y-r){
                if(y+r>map.divar[i].y1&&abs(x-map.divar[i].x1)<r){
                    return 1;
                }

            }
            else{
                if(map.divar[i].y2>y-r&&abs(x-map.divar[i].x1)<r){
                    return 1;
                }
            }
        }
        else{
            if(x-r>map.divar[i].x1){
                if(x-r<map.divar[i].x2&&abs(y-map.divar[i].y1)<r){
                    return 2;
                }
            }
            else{
                if(map.divar[i].x1<x+r&&abs(y-map.divar[i].y1)<r){
                    return 2;
                }
            }
        }
    }
    return 0;
}

int saresh(int x,int y,int x2,int y2,Map map){
    bool amood;
    double mlool;
    if(x2!=x) {
        amood=true;
        mlool = (y2 - y) / (x2 - x);
    }
    else{
        amood=false;
    }
    for(int i=0;i<map.tedad;i++){
        if(map.divar[i].x1==map.divar[i].x2){
            if(amood==true&&x==map.divar[i].x2){
                if((map.divar[i].y1<y&&y<map.divar[i].y2)||(map.divar[i].y1<y2&&y2<map.divar[i].y2)){
                    return 1;
                }
            }
            if(amood==false&&map.divar[i].y1<(mlool*(map.divar[i].x1-x)+y)&&(mlool*(map.divar[i].x1-x)+y)<map.divar[i].y2){
                return 1;
            }

        }
        if(map.divar[i].y1==map.divar[i].y2){
            if(amood==false&&mlool==0){
                if(y==map.divar[i].y1){
                    if((map.divar[i].x1<x&&x<map.divar[i].x2)||(map.divar[i].x1<x2&&x2<map.divar[i].x2)){
                        return 1;
                    }
                }
            }
            if(amood==true){
                if(map.divar[i].x1<x&&map.divar[i].x2>x){
                    return 1;
                }
            }
            if(amood==false&&mlool!=0){
                if(map.divar[i].x1<(map.divar[i].y1-y)/mlool+x&&map.divar[i].x2>(map.divar[i].y1-y)/mlool+x){
                    return 1;
                }
            }
        }
    }
    return 0;
}
