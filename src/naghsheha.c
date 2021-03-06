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
int min(double a, double b){
    if(a>b)return b;
    return a;
}
int max(double a, double b){
    if(a>b)return a;
    return b;
}
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
        thickLineRGBA(renderer,map->divar[i].x1,map->divar[i].y1,map->divar[i].x2,map->divar[i].y2,1,0,0,0,255);
    }
}
int divarkhor(Map map, double x, double y, double r){
    int rast=0, chap=0;
    for(int i=0;i<map.tedad;i++){
        if(map.divar[i].x1==map.divar[i].x2){
            if(map.divar[i].y1>y-r){
                if(y+r>map.divar[i].y1&&abs(x-map.divar[i].x1)<r){
                    rast=1;
                }

            }
            else{
                if(map.divar[i].y2>y-r&&abs(x-map.divar[i].x1)<r){
                    rast= 1;
                }
            }
        }
        else{
            if(x-r>map.divar[i].x1){
                if(x-r<map.divar[i].x2&&abs(y-map.divar[i].y1)<r){
                    chap= 1;
                }
            }
            else{
                if(map.divar[i].x1<x+r&&abs(y-map.divar[i].y1)<r){
                    chap= 1;
                }
            }
        }
    }
    if(rast==0&&chap==0)return 0;
    if(rast==1&&chap==1)return 5;
    if(rast==1)return 1;
    if(chap==1)return 2;
}

int saresh(int x1,int y1,int x2,int y2,Map map){
    bool amood;
    double mlool;
    if(x2==x1) {
        amood=true;
    }
    else{
        amood=false;
        mlool = (y2 - y1) / (x2 - x1);
    }
    for(int i=0;i<map.tedad;i++){
        if(map.divar[i].x1==map.divar[i].x2){
            if(amood==true&&x1==map.divar[i].x2){
                if((map.divar[i].y1<y1&&y1<map.divar[i].y2)||(map.divar[i].y1<y2&&y2<map.divar[i].y2)){
                    return 1;
                }
            }
            if(amood==false&&map.divar[i].y1<(mlool*(map.divar[i].x1-x1)+y1)&&(mlool*(map.divar[i].x1-x1)+y1)<map.divar[i].y2){
                return 1;
            }

        }
        if(map.divar[i].y1==map.divar[i].y2){
            if(amood==false&&mlool==0){
                if(y1==map.divar[i].y1){
                    if((map.divar[i].x1<x1&&x1<map.divar[i].x2)||(map.divar[i].x1<x2&&x2<map.divar[i].x2)){
                        return 1;
                    }
                }
            }
            if(amood==true){
                if(map.divar[i].x1<x1&&map.divar[i].x2>x1&&map.divar[i].y2>min(y1,y2)&&map.divar[i].y2<max(y1,y2)) {
                    return 1;
                }
            }
            if(amood==false&&mlool!=0){
                if(map.divar[i].x1<(map.divar[i].y1-y1)/mlool+x1&&map.divar[i].x2>(map.divar[i].y1-y1)/mlool+x1){
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
    dfs(rand()%5,rand()%5,khoone,mark,shomare);
    dor(shomare,khoone);
}
//void rasja(box khoone[][5][5],SDL_Renderer *renderer,Map *map, double tool, double arz) {
//    double jb=(750-tool)/2;
//    int te=0;
//    for(int k=1;k<=4;k++){
//        if(k==1){
//            for (int i = 0; i < 5; i++) {
//                for (int j = 0; j < 5; j++) {
//                int xx = j;
//                int yy = i;
//                if (khoone[i][j][k].divup == true) {
//                    thickLineRGBA(renderer, jb+xx *tool/10, yy*arz/10, jb+xx * tool/10 + tool/10, yy * arz/10, 2,80, 80,80, 255);
////
//                }
//                if (khoone[i][j][k].divdon == true) {
//                    thickLineRGBA(renderer, jb+xx * tool/10, yy * arz/10 + arz/10, jb+xx * tool/10 + tool/10, yy * arz/10 + arz/10,2, 80, 80, 80, 255);
////
//                }
//                if (khoone[i][j][k].divright == true) {
//                    thickLineRGBA(renderer, jb+xx * tool/10 + tool/10, yy * arz/10, jb+xx * tool/10 + tool/10, yy * arz/10 + arz/10,2, 80, 80, 80, 255);
////
//                }
//                if (khoone[i][j][k].divleft == true) {
//                    thickLineRGBA(renderer, jb+xx * tool/10, yy * arz/10, jb+xx * tool/10, yy *arz/10 + arz/10, 2,80,80,80, 255);
////
//                }
//            }
//        }
//    }
//    if(k==2) {
//        for (int i = 0; i < 5; i++) {
//            for (int j = 0; j < 5; j++) {
//                int xx = j;
//                int yy = i;
//                if (khoone[i][j][k].divup == true) {
//                    thickLineRGBA(renderer, tool/2 + jb+xx * tool/10, yy * arz/10, tool/2 + jb+xx * tool/10 + tool/10, yy * arz/10,2, 80, 80, 80, 255);
////
//                }
//                if (khoone[i][j][k].divdon == true) {
//                    thickLineRGBA(renderer, tool/2 + jb+xx * tool/10, yy * arz/10 + arz/10, tool/2 + jb+xx * tool/10 + tool/10, yy * arz/10 + arz/10,2, 80, 80, 80, 255);
////
//                }
//                if (khoone[i][j][k].divright == true) {
//                    thickLineRGBA(renderer, tool/2 + jb+xx * tool/10 + tool/10, yy * arz/10, tool/2 + jb+xx * tool/10 + tool/10, yy * arz/10 + arz/10,2, 80, 80, 80, 255);
////
//                }
//                if (khoone[i][j][k].divleft == true) {
//                    thickLineRGBA(renderer, tool/2 + jb+xx * tool/10, yy * arz/10, tool/2 + jb+xx * tool/10, yy * arz/10 +arz/10,2, 80, 80, 80, 255);
////
//                }
//            }
//        }
//    }
//    if(k==3){
//    for (int i = 0; i < 5; i++) {
//        for (int j = 0; j < 5; j++) {
//            int xx = j;
//            int yy = i;
//            if (khoone[i][j][k].divup == true) {
//                thickLineRGBA(renderer, jb+xx * tool/10, arz/2 + yy * arz/10, jb+xx * tool/10 + tool/10, arz/2 + yy * arz/10,2, 80, 80, 80, 255);
////
//            }
//            if (khoone[i][j][k].divdon == true) {
//                thickLineRGBA(renderer, jb+xx * tool/10, arz/2 + yy * arz/10 + arz/10, jb+xx * tool/10 + tool/10, arz/2 + yy * arz/10 + arz/10,2, 80, 80, 80, 255);
////
//            }
//            if (khoone[i][j][k].divright == true) {
//                thickLineRGBA(renderer, jb+xx * tool/10 + tool/10, arz/2 + yy * arz/10, jb+xx * tool/10 + tool/10, arz/2 + yy * arz/10 + arz/10,2, 80, 80, 80, 255);
////
//            }
//            if (khoone[i][j][k].divleft == true) {
//                thickLineRGBA(renderer, jb+xx * tool/10, arz/2 + yy * arz/10, jb+xx * tool/10, arz/2 + yy * arz/10 + arz/10, 2,80, 80, 80, 255);
////
//            }
//        }
//    }
//        }
//    if(k==4) {
//        for (int i = 0; i < 5; i++) {
//            for (int j = 0; j < 5; j++) {
//                int xx = j;
//                int yy = i;
//                if (khoone[i][j][k].divup == true) {
//                    thickLineRGBA(renderer, tool/2 + jb+xx * tool/10, arz/2 + yy * arz/10, tool/2 + jb+xx * tool/10 + tool/10, arz/2 + yy * arz/10,2 ,80, 80, 80, 255);
////
//                }
//                if (khoone[i][j][k].divdon == true) {
//                    thickLineRGBA(renderer, tool/2 + jb+xx * tool/10, arz/2 + yy *arz/10 + arz/10, tool/2 + jb+xx * tool/10 + tool/10, arz/2 + yy * arz/10 +arz/10,2 ,80, 80,80,255);
////
//                }
//                if (khoone[i][j][k].divright == true) {
//                    thickLineRGBA(renderer, tool/2 + jb+xx * tool/10 + tool/10, arz/2 + yy * arz/10, tool/2 + jb+xx * tool/10 + tool/10, arz/2 + yy *arz/10 + arz/10,2 ,80, 80,80,255);
////
//                }
//                if (khoone[i][j][k].divleft == true) {
//                    thickLineRGBA(renderer, tool/2 + jb+xx * tool/10, arz/2 + yy * arz/10, tool/2 + jb+xx * tool/10, arz/2 + yy *arz/10 + arz/10,2, 80, 80, 80, 255);
//                }
//            }
//        }
//    }
//    }
//}
int aval(box khoone[][5][5],Map *map,double  tool, double arz){
    int te=0;
    double jb=(750-tool)/2;
    for(int k=1;k<=4;k++){
        if(k==1){
            for (int i = 0; i < 5; i++) {
                for (int j = 0; j < 5; j++) {
                    int xx = j;
                    int yy = i;
                    if (khoone[i][j][k].divup == true) {
                    (*map).divar[te].x1 = jb+xx * tool/10;
                    (*map).divar[te].y1 = yy * arz/10;
                    (*map).divar[te].x2 = jb+xx * tool/10 + tool/10;
                    (*map).divar[te].y2 = yy * arz/10;
                        te++;
                    }
                    if (khoone[i][j][k].divdon == true) {
                    (*map).divar[te].x1 = jb+xx * tool/10;
                    (*map).divar[te].y1 = yy * arz/10 + arz/10;
                    (*map).divar[te].x2 = jb+xx * tool/10 + tool/10;
                    (*map).divar[te].y2 = yy * arz/10 + arz/10;
                        te++;
                    }
                    if (khoone[i][j][k].divright == true) {
                    (*map).divar[te].x1 = jb+xx * tool/10 + tool/10;
                    (*map).divar[te].y1 = yy * arz/10;
                    (*map).divar[te].x2 = jb+xx * tool/10 + tool/10;
                    (*map).divar[te].y2 = yy * arz/10 + arz/10;
                        te++;
                    }
                    if (khoone[i][j][k].divleft == true) {
                    (*map).divar[te].x1 = jb+xx * tool/10;
                    (*map).divar[te].y1 = yy * arz/10;
                    (*map).divar[te].x2 = jb+xx * tool/10;
                    (*map).divar[te].y2 = yy * arz/10 + arz/10;
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
                    (*map).divar[te].x1 = tool/2 + jb+xx * tool/10;
                    (*map).divar[te].y1 = yy * arz/10;
                    (*map).divar[te].x2 = tool/2 + jb+xx * tool/10+tool/10;
                    (*map).divar[te].y2 = yy * arz/10 ;
                        te++;
                    }
                    if (khoone[i][j][k].divdon == true) {
                    (*map).divar[te].x1 = tool/2 + jb+xx * tool/10;
                    (*map).divar[te].y1 = yy * arz/10+arz/10;
                    (*map).divar[te].x2 = tool/2 + jb+xx * tool/10+tool/10;
                    (*map).divar[te].y2 = yy * arz/10 + arz/10;
                    te++;
                    }
                    if (khoone[i][j][k].divright == true) {
                    (*map).divar[te].x1 = tool/2 + jb+xx * tool/10+tool/10;
                    (*map).divar[te].y1 = yy * arz/10;
                    (*map).divar[te].x2 = tool/2 + jb+xx * tool/10+tool/10;
                    (*map).divar[te].y2 = yy * arz/10 + arz/10;
                    te++;
                    }
                    if (khoone[i][j][k].divleft == true) {
                    (*map).divar[te].x1 = tool/2 + jb+xx * tool/10;
                    (*map).divar[te].y1 = yy * arz/10;
                    (*map).divar[te].x2 = tool/2 + jb+xx * tool/10;
                    (*map).divar[te].y2 = yy * arz/10 + arz/10;
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
                (*map).divar[te].x1 = jb+xx * tool/10;
                (*map).divar[te].y1 = arz/2 + yy * arz/10;
                (*map).divar[te].x2 = jb+xx * tool/10+tool/10;
                (*map).divar[te].y2 = arz/2 + yy * arz/10 ;
                te++;
                    }
                    if (khoone[i][j][k].divdon == true) {
                (*map).divar[te].x1 = jb+xx * tool/10;
                (*map).divar[te].y1 = arz/2 + yy * arz/10+arz/10;
                (*map).divar[te].x2 = jb+xx * tool/10+tool/10;
                (*map).divar[te].y2 = arz/2 + yy * arz/10 + arz/10;
                te++;
                    }
                    if (khoone[i][j][k].divright == true) {
                (*map).divar[te].x1 = jb+xx * tool/10+tool/10;
                (*map).divar[te].y1 = arz/2 + yy * arz/10;
                (*map).divar[te].x2 = jb+xx * tool/10+tool/10;
                (*map).divar[te].y2 = arz/2 + yy * arz/10 + arz/10;
                        te++;
                    }
                    if (khoone[i][j][k].divleft == true) {
                (*map).divar[te].x1 = jb+xx * tool/10;
                (*map).divar[te].y1 = arz/2 + yy * arz/10;
                (*map).divar[te].x2 = jb+xx * tool/10;
                (*map).divar[te].y2 = arz/2 + yy * arz/10 + arz/10;
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
                        (*map).divar[te].x1 = tool/2 + jb+xx * tool/10;
                    (*map).divar[te].y1 = arz/2 + yy * arz/10;
                    (*map).divar[te].x2 = tool/2 + jb+xx * tool/10+tool/10;
                    (*map).divar[te].y2 = arz/2 + yy * arz/10 ;
                    te++;

                    }
                    if (khoone[i][j][k].divdon == true) {

                    (*map).divar[te].x1 = tool/2 + jb+xx * tool/10;
                    (*map).divar[te].y1 = arz/2 + yy * arz/10+arz/10;
                    (*map).divar[te].x2 = tool/2 + jb+xx * tool/10+tool/10;
                    (*map).divar[te].y2 = arz/2 + yy * arz/10 + arz/10;
                    te++;
                    }
                    if (khoone[i][j][k].divright == true) {
                    (*map).divar[te].x1 = tool/2 + jb+xx * tool/10+tool/10;
                    (*map).divar[te].y1 = arz/2 + yy * arz/10;
                    (*map).divar[te].x2 = tool/2 + jb+xx * tool/10+tool/10;
                    (*map).divar[te].y2 = arz/2 + yy * arz/10 + arz/10;
                    te++;
                    }
                    if (khoone[i][j][k].divleft == true) {
                    (*map).divar[te].x1 = tool/2 + jb+xx * tool/10;
                    (*map).divar[te].y1 = arz/2 + yy * arz/10;
                    (*map).divar[te].x2 = tool/2 + jb+xx * tool/10;
                    (*map).divar[te].y2 = arz/2 + yy * arz/10 + arz/10;
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
        int e=0;
        while(e<15) {
            int ra=rand()%4;
            if (ra==0&&x - 1 >= 0 && mark[x - 1][y] == 0) {
                khoone[x][y][shomare].divup = false;
                khoone[x - 1][y][shomare].divdon = false;
                dfs(x - 1, y, khoone, mark, shomare);
            }
            if (ra==1&&y + 1 <= 4 && mark[x][y + 1] == 0) {
                khoone[x][y][shomare].divright = false;
                khoone[x][y + 1][shomare].divleft = false;
                dfs(x, y + 1, khoone, mark, shomare);
            }
            if (ra==2&&y - 1 >= 0 && mark[x][y - 1] == 0) {
                khoone[x][y][shomare].divleft = false;
                khoone[x][y - 1][shomare].divright = false;
                dfs(x, y - 1, khoone, mark, shomare);
            }
            if (ra==3&&x + 1 <= 4 && mark[x + 1][y] == 0) {
                khoone[x][y][shomare].divdon = false;
                khoone[x + 1][y][shomare].divup = false;
                dfs(x + 1, y, khoone, mark, shomare);
            }
            e++;
        }
    return;
}
void dor(int sho,box khoone[][5][5]){
    if(sho==1){
        for(int i=0;i<5;i++){
            for(int j=0;j<5;j++){
                if(i==0){
                    khoone[i][j][sho].divup=true;
                }
                if(j==0){
                    khoone[i][j][sho].divleft=true;
                }
            }
        }
    }
    if(sho==2){
        for(int i=0;i<5;i++){
            for(int j=0;j<5;j++){
                if(i==0){
                    khoone[i][j][sho].divup=true;
                }
                if(j==4){
                    khoone[i][j][sho].divright=true;
                }
            }
        }
    }
    if(sho==3){
        for(int i=0;i<5;i++){
            for(int j=0;j<5;j++){
                if(i==4){
                    khoone[i][j][sho].divdon=true;
                }
                if(j==0){
                    khoone[i][j][sho].divleft=true;
                }
            }
        }
    }
    if(sho==4){
        for(int i=0;i<5;i++){
            for(int j=0;j<5;j++){
                if(i==4){
                    khoone[i][j][sho].divdon=true;
                }
                if(j==4){
                    khoone[i][j][sho].divright=true;
                }
            }
        }
    }
}

