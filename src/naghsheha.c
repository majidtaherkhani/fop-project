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
#include<time.h>

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

void maprand(int shomare,box khoone[][5][5]){
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++) {
            khoone[i][j][shomare].divup = true;
            khoone[i][j][shomare].divdon = true;
            khoone[i][j][shomare].divleft = true;
            khoone[i][j][shomare].divright = true;
        }
    }
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            if(i==0){
                khoone[i][j][shomare].divup=false;
            }
            if(i==4){
                khoone[i][j][shomare].divdon=false;
            }
            if(j==0){
                khoone[i][j][shomare].divleft=false;
            }
            if(j==4){
                khoone[i][j][shomare].divright=false;
            }
        }
    }
    int mark[5][5];
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            mark[i][j]=0;
        }
    }

    int random,randoma;
    random=rand()%5;
    randoma=rand()%5;
    dfs(rand()%5,rand()%5,khoone,mark,shomare);
}
void rasja(box khoone[][5][5],SDL_Renderer *renderer,Map *map) {
    int te=0;
    for(int k=1;k<=4;k++){
        if(k==1){
            for (int i = 0; i < 5; i++) {
                for (int j = 0; j < 5; j++) {
                int xx = j;
                int yy = i;
                if (khoone[i][j][k].divup == true) {
                    lineRGBA(renderer, xx * 60, yy * 60, xx * 60 + 60, yy * 60, 0, 0, 0, 255);
//
                }
                if (khoone[i][j][k].divdon == true) {
                    lineRGBA(renderer, xx * 60, yy * 60 + 60, xx * 60 + 60, yy * 60 + 60, 0, 0, 0, 255);
//
                }
                if (khoone[i][j][k].divright == true) {
                    lineRGBA(renderer, xx * 60 + 60, yy * 60, xx * 60 + 60, yy * 60 + 60, 0, 0, 0, 255);
//
                }
                if (khoone[i][j][k].divleft == true) {
                    lineRGBA(renderer, xx * 60, yy * 60, xx * 60, yy * 60 + 60, 0, 0, 0, 255);
//
                }
            }
        }
    }
    if(k==2) {
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                int xx = j;
                int yy = i;
                if (khoone[i][j][k].divup == true) {
                    lineRGBA(renderer, 300 + xx * 60, yy * 60, 300 + xx * 60 + 60, yy * 60, 0, 0, 0, 255);
//
                }
                if (khoone[i][j][k].divdon == true) {
                    lineRGBA(renderer, 300 + xx * 60, yy * 60 + 60, 300 + xx * 60 + 60, yy * 60 + 60, 0, 0, 0, 255);
//
                }
                if (khoone[i][j][k].divright == true) {
                    lineRGBA(renderer, 300 + xx * 60 + 60, yy * 60, 300 + xx * 60 + 60, yy * 60 + 60, 0, 0, 0, 255);
//
                }
                if (khoone[i][j][k].divleft == true) {
                    lineRGBA(renderer, 300 + xx * 60, yy * 60, 300 + xx * 60, yy * 60 + 60, 0, 0, 0, 255);
//
                }
            }
        }
    }
    if(k==3){
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            int xx = j;
            int yy = i;
            if (khoone[i][j][k].divup == true) {
                lineRGBA(renderer, xx * 60, 300 + yy * 60, xx * 60 + 60, 300 + yy * 60, 0, 0, 0, 255);
//
            }
            if (khoone[i][j][k].divdon == true) {
                lineRGBA(renderer, xx * 60, 300 + yy * 60 + 60, xx * 60 + 60, 300 + yy * 60 + 60, 0, 0, 0, 255);
//
            }
            if (khoone[i][j][k].divright == true) {
                lineRGBA(renderer, xx * 60 + 60, 300 + yy * 60, xx * 60 + 60, 300 + yy * 60 + 60, 0, 0, 0, 255);
//
            }
            if (khoone[i][j][k].divleft == true) {
                lineRGBA(renderer, xx * 60, 300 + yy * 60, xx * 60, 300 + yy * 60 + 60, 0, 0, 0, 255);
//
            }
        }
    }
        }
    if(k==4) {
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                int xx = j;
                int yy = i;
                if (khoone[i][j][k].divup == true) {
                    lineRGBA(renderer, 300 + xx * 60, 300 + yy * 60, 300 + xx * 60 + 60, 300 + yy * 60, 0, 0, 0, 255);
//
                }
                if (khoone[i][j][k].divdon == true) {
                    lineRGBA(renderer, 300 + xx * 60, 300 + yy * 60 + 60, 300 + xx * 60 + 60, 300 + yy * 60 + 60, 0, 0,0,255);
//
                }
                if (khoone[i][j][k].divright == true) {
                    lineRGBA(renderer, 300 + xx * 60 + 60, 300 + yy * 60, 300 + xx * 60 + 60, 300 + yy * 60 + 60, 0, 0,0,255);
//
                }
                if (khoone[i][j][k].divleft == true) {
                    lineRGBA(renderer, 300 + xx * 60, 300 + yy * 60, 300 + xx * 60, 300 + yy * 60 + 60, 0, 0, 0, 255);
                }
            }
        }
    }
    }
}
int aval(box khoone[][5][5],Map *map) {
    int te=0;
    for(int k=1;k<=4;k++){
        if(k==1){
            for (int i = 0; i < 5; i++) {
                for (int j = 0; j < 5; j++) {
                    int xx = j;
                    int yy = i;
                    if (khoone[i][j][k].divup == true) {
                    (*map).divar[te].x1 = xx * 60;
                    (*map).divar[te].y1 = yy * 60;
                    (*map).divar[te].x2 = xx * 60 + 60;
                    (*map).divar[te].y2 = yy * 60;
                        te++;
                    }
                    if (khoone[i][j][k].divdon == true) {
                    (*map).divar[te].x1 = xx * 60;
                    (*map).divar[te].y1 = yy * 60 + 60;
                    (*map).divar[te].x2 = xx * 60 + 60;
                    (*map).divar[te].y2 = yy * 60 + 60;
                        te++;
                    }
                    if (khoone[i][j][k].divright == true) {
                    (*map).divar[te].x1 = xx * 60 + 60;
                    (*map).divar[te].y1 = yy * 60;
                    (*map).divar[te].x2 = xx * 60 + 60;
                    (*map).divar[te].y2 = yy * 60 + 60;
                        te++;
                    }
                    if (khoone[i][j][k].divleft == true) {
                    (*map).divar[te].x1 = xx * 60;
                    (*map).divar[te].y1 = yy * 60;
                    (*map).divar[te].x2 = xx * 60;
                    (*map).divar[te].y2 = yy * 60 + 60;
                        te++;
                    }
                }
            }
        }
        if(k==2) {
            for (int i = 0; i < 5; i++) {
                for (int j = 0; j < 5; j++) {
                    int xx = j;
                    int yy = i;
                    if (khoone[i][j][k].divup == true) {
                    (*map).divar[te].x1 = 300 + xx * 60;
                    (*map).divar[te].y1 = yy * 60;
                    (*map).divar[te].x2 = 300 + xx * 60+60;
                    (*map).divar[te].y2 = yy * 60 ;
                        te++;
                    }
                    if (khoone[i][j][k].divdon == true) {
                    (*map).divar[te].x1 = 300 + xx * 60;
                    (*map).divar[te].y1 = yy * 60+60;
                    (*map).divar[te].x2 = 300 + xx * 60+60;
                    (*map).divar[te].y2 = yy * 60 + 60;
                    te++;
                    }
                    if (khoone[i][j][k].divright == true) {
                    (*map).divar[te].x1 = 300 + xx * 60+60;
                    (*map).divar[te].y1 = yy * 60;
                    (*map).divar[te].x2 = 300 + xx * 60+60;
                    (*map).divar[te].y2 = yy * 60 + 60;
                    te++;
                    }
                    if (khoone[i][j][k].divleft == true) {
                    (*map).divar[te].x1 = 300 + xx * 60;
                    (*map).divar[te].y1 = yy * 60;
                    (*map).divar[te].x2 = 300 + xx * 60;
                    (*map).divar[te].y2 = yy * 60 + 60;
                    te++;
                    }
                }
            }
        }
        if(k==3){
            for (int i = 0; i < 5; i++) {
                for (int j = 0; j < 5; j++) {
                    int xx = j;
                    int yy = i;
                    if (khoone[i][j][k].divup == true) {
                (*map).divar[te].x1 = xx * 60;
                (*map).divar[te].y1 = 300 + yy * 60;
                (*map).divar[te].x2 = xx * 60+60;
                (*map).divar[te].y2 = 300 + yy * 60 ;
                te++;
                    }
                    if (khoone[i][j][k].divdon == true) {
                (*map).divar[te].x1 = xx * 60;
                (*map).divar[te].y1 = 300 + yy * 60+60;
                (*map).divar[te].x2 = xx * 60+60;
                (*map).divar[te].y2 = 300 + yy * 60 + 60;
                te++;
                    }
                    if (khoone[i][j][k].divright == true) {
                (*map).divar[te].x1 = xx * 60+60;
                (*map).divar[te].y1 = 300 + yy * 60;
                (*map).divar[te].x2 = xx * 60+60;
                (*map).divar[te].y2 = 300 + yy * 60 + 60;
                        te++;
                    }
                    if (khoone[i][j][k].divleft == true) {
                (*map).divar[te].x1 = xx * 60;
                (*map).divar[te].y1 = 300 + yy * 60;
                (*map).divar[te].x2 = xx * 60;
                (*map).divar[te].y2 = 300 + yy * 60 + 60;
                        te++;
                    }
                }
            }
        }
        if(k==4) {
            for (int i = 0; i < 5; i++) {
                for (int j = 0; j < 5; j++) {
                    int xx = j;
                    int yy = i;
                    if (khoone[i][j][k].divup == true) {
                        (*map).divar[te].x1 = 300 + xx * 60;
                    (*map).divar[te].y1 = 300 + yy * 60;
                    (*map).divar[te].x2 = 300 + xx * 60+60;
                    (*map).divar[te].y2 = 300 + yy * 60 ;
                    te++;

                    }
                    if (khoone[i][j][k].divdon == true) {

                    (*map).divar[te].x1 = 300 + xx * 60;
                    (*map).divar[te].y1 = 300 + yy * 60+60;
                    (*map).divar[te].x2 = 300 + xx * 60+60;
                    (*map).divar[te].y2 = 300 + yy * 60 + 60;
                    te++;
                    }
                    if (khoone[i][j][k].divright == true) {
                    (*map).divar[te].x1 = 300 + xx * 60+60;
                    (*map).divar[te].y1 = 300 + yy * 60;
                    (*map).divar[te].x2 = 300 + xx * 60+60;
                    (*map).divar[te].y2 = 300 + yy * 60 + 60;
                    te++;
                    }
                    if (khoone[i][j][k].divleft == true) {
                    (*map).divar[te].x1 = 300 + xx * 60;
                    (*map).divar[te].y1 = 300 + yy * 60;
                    (*map).divar[te].x2 = 300 + xx * 60;
                    (*map).divar[te].y2 = 300 + yy * 60 + 60;
                    te++;
                    }
                }
            }
        }
    }
    return te;
}
void dfs(int x,int y,box khoone[][5][5],int mark[][5],int shomare){
    mark[x][y]=1;
        if ( x - 1 >= 0 && mark[x - 1][y] == 0) {
            khoone[x][y][shomare].divup = false;
            khoone[x - 1][y][shomare].divdon = false;
            dfs(x - 1, y, khoone, mark,shomare);
        }
        if ( y + 1 <= 4 && mark[x][y + 1] == 0) {
            khoone[x][y][shomare].divright = false;
            khoone[x][y + 1][shomare].divleft = false;
            dfs(x, y + 1, khoone, mark,shomare);
        }
        if (y - 1 >= 0 && mark[x][y - 1] == 0) {
            khoone[x][y][shomare].divleft = false;
            khoone[x][y - 1][shomare].divright = false;
            dfs(x, y - 1, khoone, mark,shomare);
        }
        if ( x + 1 <= 4 && mark[x + 1][y] == 0) {
            khoone[x][y][shomare].divdon = false;
            khoone[x + 1][y][shomare].divup = false;
            dfs(x + 1, y, khoone, mark,shomare);
        }
    return;
}