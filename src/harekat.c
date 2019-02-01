//
// Created by majid on 12/23/2018.
//
#include<stdio.h>
#include <stdlib.h>
#include <SDL2_gfxPrimitives.h>
#include "structha.h"
#include <stdbool.h>
#include "structha.h"
#include "naghsheha.h"
#include <math.h>
//void voroodnomre(bool a[]){
//    const Uint8* currentKeyStates = SDL_GetKeyboardState( NULL );
//    if(currentKeyStates[ SDL_SCANCODE_1 ])a[1]=true;
//    if(currentKeyStates[ SDL_SCANCODE_2 ])a[2]=true ;
//    if(currentKeyStates[ SDL_SCANCODE_3 ])a[3]=true ;
//    if(currentKeyStates[ SDL_SCANCODE_4 ])a[4]=true;
//    if(currentKeyStates[ SDL_SCANCODE_5 ])a[5]=true;
//    if(currentKeyStates[ SDL_SCANCODE_6 ])a[6]=true;
//    if(currentKeyStates[ SDL_SCANCODE_7 ])a[7]=true;
//    if(currentKeyStates[ SDL_SCANCODE_8 ])a[8]=true;
//    if(currentKeyStates[ SDL_SCANCODE_9 ])a[9]=true;
//    if(currentKeyStates[ SDL_SCANCODE_0 ]) a[0]=true;
//}
int cheksar(Map map,double x,double y, double r){
    r-=1;
    for(int i=0;i<map.tedad;i++){
        if((((map.divar[i].x1-x)*(map.divar[i].x1-x)+(map.divar[i].y1-y)*(map.divar[i].y1-y))<=r*r)||((map.divar[i].x2-x)*(map.divar[i].x2-x)+(map.divar[i].y2-y)*(map.divar[i].y2-y)<=r*r)){
            return 1;
        }
    }
    return 0;
}
int menu(){
    const Uint8* currentKeyStates = SDL_GetKeyboardState( NULL );
    if(currentKeyStates[ SDL_SCANCODE_SPACE ]){
        return 1;
    }
    if(currentKeyStates[ SDL_SCANCODE_ESCAPE ]==0){
        return 0;
    }
    return 10;
}
int savefeshar(){
    const Uint8* currentKeyStates = SDL_GetKeyboardState( NULL );
    if(currentKeyStates[ SDL_SCANCODE_Z]){
        return 1;
    }

    return 0;
}
int savejra(){
    const Uint8* currentKeyStates = SDL_GetKeyboardState( NULL );
    if(currentKeyStates[ SDL_SCANCODE_T]){
        return 1;
    }
    return 0;
}
void klid(double snake_radius,tanks tank[],int *flagtir,int step,Map map,int *flagtir2,int *s,int *ss,int *lazerbezan1,int *lazerbezan2){
    double r=snake_radius;
    const double megh=2*M_PI/90;
    const Uint8* currentKeyStates = SDL_GetKeyboardState( NULL );
//    if( currentKeyStates[ SDL_SCANCODE_UP ]/*&&cheksar(map, tank[1].x + step * cos(tank[1].zav),tank[1].y - step * sin(tank[1].zav),snake_radius)==0/*&&divarkhor(map,tank[1].x + step * cos(tank[1].zav),tank[1].y - step * sin(tank[1].zav),r)==0)&&saresh(tank[1].x + step * cos(tank[1].zav),tank[1].y - step * sin(tank[1].zav),tank[1].x + step * cos(tank[1].zav)+1.5*r*cos(tank[1].zav),tank[1].y - step * sin(tank[1].zav)-1.5*r*sin(tank[1].zav),map)==0*/)
//    {
//        //printf("salam");
//        if(divarkhor(map,tank[1].x + step * cos(tank[1].zav),tank[1].y - step * sin(tank[1].zav),r)==0) {
//            tank[1].y -= step * sin(tank[1].zav);
//            tank[1].x += step * cos(tank[1].zav);
//        }
//            if (divarkhor(map, tank[1].x + step * cos(tank[1].zav), tank[1].y - step * sin(tank[1].zav), r) == 1) {
//
//                if ((0 <= sin(tank[1].zav) && sin(tank[1].zav) <= 1 && cos(tank[1].zav) >= 0 &&
//                     cos(tank[1].zav) <= 1) ||
//                    (-1 <= sin(tank[1].zav) && sin(tank[1].zav) < 0 && cos(tank[1].zav) >= -1 &&
//                     cos(tank[1].zav) <= 0)) {
////               tank[1].y -= step * sin(tank[1].zav);
//                    tank[1].zav += 2 * (megh);
//
//                }
//                //if ((0 < sin(tank[1].zav) && sin(tank[1].zav) <= 1 && -1 <= cos(tank[1].zav) &&cos(tank[1].zav) <= 0) ||(-1 <= sin(tank[1].zav) && sin(tank[1].zav) <= 0 && 0 <= cos(tank[1].zav) &&cos(tank[1].zav) <= 1)) {
//                    //  tank[1].y -= step * sin(tank[1].zav);
//                    else{
//                    tank[1].zav -= (megh/2);
//                }
//            }
//            if (divarkhor(map, tank[1].x + step * cos(tank[1].zav), tank[1].y - step * sin(tank[1].zav), r) == 2) {
////            if(-1<cos(tank[1].zav)&&cos(tank[1].zav)<0){
////                tank[1].x += step * cos(tank[1].zav);
////            }
////            if((0<cos(tank[1].zav)&&cos(tank[1].zav)<1)){
////                tank[1].x += step * cos(tank[1].zav);
////            }
//                if ((0 <= sin(tank[1].zav) && sin(tank[1].zav) <= 1 && cos(tank[1].zav) >= 0 &&cos(tank[1].zav) <= 1) ||(-1 <= sin(tank[1].zav) && sin(tank[1].zav) <= 0 && -1<=cos(tank[1].zav) &&0<=cos(tank[1].zav))) {
////               tank[1].y -= step * sin(tank[1].zav);
//                    tank[1].zav -= (megh);
//
//                }
//               // if ((0 <= sin(tank[1].zav) && sin(tank[1].zav) <= 1 && -1 <= cos(tank[1].zav) &&cos(tank[1].zav) <= 0) ||(-1 <= sin(tank[1].zav) && sin(tank[1].zav) <= 0 && 0 <= cos(tank[1].zav) &&cos(tank[1].zav) <= 1)) {
//                    //  tank[1].y -= step * sin(tank[1].zav);
//                    else{
//                    tank[1].zav += (megh/2);
//                }
//
//            }
//
//    }
//    if( currentKeyStates[ SDL_SCANCODE_DOWN ]&&cheksar(map, tank[1].x - step * cos(tank[1].zav),tank[1].y + step * sin(tank[1].zav),snake_radius)==0/*&&divarkhor(map, tank[1].x -step*cos(tank[1].zav), tank[1].y +step*sin(tank[1].zav),r)==0&&saresh(tank[1].x - step * cos(tank[1].zav),tank[1].y + step * sin(tank[1].zav),tank[1].x - step * cos(tank[1].zav)+1.5*r*cos(tank[1].zav),tank[1].y + step * sin(tank[1].zav)-1.5*r*sin(tank[1].zav),map)==0*/)
//    {
//        if(divarkhor(map, tank[1].x -step*cos(tank[1].zav), tank[1].y +step*sin(tank[1].zav),r)==0) {
//            tank[1].y += step * sin(tank[1].zav);
//            tank[1].x -= step * cos(tank[1].zav);
//        }
//        if(divarkhor(map, tank[1].x -step*cos(tank[1].zav), tank[1].y +step*sin(tank[1].zav),r)){
//
//        }
//        if(divarkhor(map, tank[1].x -step*cos(tank[1].zav), tank[1].y +step*sin(tank[1].zav),r)==2){
//
//        }
//    }
//    if( currentKeyStates[ SDL_SCANCODE_LEFT ]/* &&saresh(tank[1].x,tank[1].y,tank[1].x+1.5*r*cos(tank[1].zav+megh),tank[1].y-1.5*r*sin(tank[1].y+megh),map)==0*/)
//    {
//        tank[1].zav+=megh;
//    }
//    if( currentKeyStates[ SDL_SCANCODE_RIGHT ]/*&&saresh(tank[1].x,tank[1].y,tank[1].x+1.5*r*cos(tank[1].zav-megh),tank[1].y-1.5*r*sin(tank[1].y-megh),map)==0 */)
//    {
//        tank[1].zav-=megh;
//    }
//    if(currentKeyStates[ SDL_SCANCODE_M ]==0){
//        *flagtir=0;
//    }
//    if(currentKeyStates[ SDL_SCANCODE_M ]&&*flagtir==0) {
//        if (tank[1].laizer == 0){
//            for (int i = 0; i < 5; i++) {
//                if (tank[1].has == true && tank[1].tir[i].por == false) {
//                    tank[1].tir[i].por = true;
//                    tank[1].tir[i].zavtir = tank[1].zav;
//                    tank[1].tir[i].x = tank[1].x + 1.5 * r * cos(tank[1].zav);
//                    tank[1].tir[i].y = tank[1].y - 1.5 * r * sin(tank[1].zav);
//                    *flagtir = 1;
//                    break;
//                }
//            }
//        }
//        else{
//            if(*s==0){
//                tank[1].tir[5].x = tank[1].x + 1.5 * r * cos(tank[1].zav);
//                tank[1].tir[5].y = tank[1].y - 1.5 * r * sin(tank[1].zav);
//                tank[1].tir[5].zavtir=tank[1].zav;
//                tank[1].tir[5].por = true;
//                *s=1;
//                *flagtir = 1;
//            }
//            else{
//                for(int i=6;i<15;i++){
//                    tank[1].tir[i].x=tank[1].tir[5].x;tank[1].tir[i].y=tank[1].tir[5].y;
//                    tank[1].tir[i].zavtir=(2*3.14/9)*i;
//                    tank[1].tir[i].por=true;
//                }
//                tank[1].tir[5].por=false;
//                *s=0;
//                tank[1].laizer =0;
//                *flagtir = 1;
//            }
//
//        }
//
//    }
    if( currentKeyStates[ SDL_SCANCODE_W ]&&cheksar(map, tank[2].x + step * cos(tank[2].zav),tank[2].y - step * sin(tank[2].zav),snake_radius)==0/*&&divarkhor(map,tank[1].x + step * cos(tank[1].zav),tank[1].y - step * sin(tank[1].zav),r)==0)&&saresh(tank[1].x + step * cos(tank[1].zav),tank[1].y - step * sin(tank[1].zav),tank[1].x + step * cos(tank[1].zav)+1.5*r*cos(tank[1].zav),tank[1].y - step * sin(tank[1].zav)-1.5*r*sin(tank[1].zav),map)==0*/)
    {
        //printf("salam");
        if(divarkhor(map,tank[2].x + step * cos(tank[2].zav),tank[2].y - step * sin(tank[2].zav),r)==0) {
            tank[2].y -= step * sin(tank[2].zav);
            tank[2].x += step * cos(tank[2].zav);
        }
        if (divarkhor(map, tank[2].x + step * cos(tank[2].zav), tank[2].y - step * sin(tank[2].zav), r) == 1) {

            if ((0 <= sin(tank[2].zav) && sin(tank[2].zav) <= 1 && cos(tank[2].zav) >= 0 &&
                 cos(tank[2].zav) <= 1) ||
                (-1 <= sin(tank[2].zav) && sin(tank[2].zav) < 0 && cos(tank[2].zav) >= -1 &&
                 cos(tank[2].zav) <= 0)) {
//               tank[1].y -= step * sin(tank[1].zav);
                tank[1].zav += ( (megh)/2);

            }
           // if ((0 < sin(tank[2].zav) && sin(tank[2].zav) <= 1 && -1 <= cos(tank[2].zav) &&cos(tank[2].zav) <= 0) ||(-1 <= sin(tank[2].zav) && sin(tank[2].zav) <= 0 && 0 <= cos(tank[2].zav) &&cos(tank[2].zav) <= 1)) {
                //  tank[1].y -= step * sin(tank[1].zav);
                else{
                tank[2].zav -= (megh/2);
            }
        }
        if (divarkhor(map, tank[2].x + step * cos(tank[2].zav), tank[2].y - step * sin(tank[2].zav), r) == 2) {
//            if(-1<cos(tank[1].zav)&&cos(tank[1].zav)<0){
//                tank[1].x += step * cos(tank[1].zav);
//            }
//            if((0<cos(tank[1].zav)&&cos(tank[1].zav)<1)){
//                tank[1].x += step * cos(tank[1].zav);
//            }
            if ((0 <= sin(tank[2].zav) && sin(tank[2].zav) <= 1 && cos(tank[2].zav) >= 0 &&
                 cos(tank[2].zav) <= 1) ||
                (-1 <= sin(tank[2].zav) && sin(tank[2].zav) <= 0 && cos(tank[2].zav) >= -1 &&
                 cos(tank[2].zav) <= 0)) {
//               tank[1].y -= step * sin(tank[1].zav);
                tank[2].zav -= (megh/2);

            }
           // if ((0 <= sin(tank[2].zav) && sin(tank[2].zav) <= 1 && -1 <= cos(tank[2].zav) &&cos(tank[2].zav) <= 0) ||(-1 <= sin(tank[2].zav) && sin(tank[2].zav) <= 0 && 0 <= cos(tank[2].zav) &&cos(tank[2].zav) <= 1)) {
                //  tank[1].y -= step * sin(tank[1].zav);
                else{
                tank[2].zav += (megh/2);
            }

        }

    }
    if( currentKeyStates[ SDL_SCANCODE_S ]&&divarkhor(map, tank[2].x -step*cos(tank[2].zav), tank[2].y +step*sin(tank[2].zav),r)==0 &&cheksar(map, tank[2].x - step * cos(tank[2].zav),tank[2].y + step * sin(tank[2].zav),snake_radius)==0)
    {
        tank[2].y +=step*sin(tank[2].zav);
        tank[2].x -=step*cos(tank[2].zav);
    }
    if( currentKeyStates[ SDL_SCANCODE_A ] )
    {
        tank[2].zav+=megh;
    }
    if( currentKeyStates[ SDL_SCANCODE_D ] )
    {
        tank[2].zav-=megh;
    }
    if(currentKeyStates[ SDL_SCANCODE_F ]==0){
        *flagtir2=0;
    }
    if(currentKeyStates[ SDL_SCANCODE_F ]&&*flagtir2==0){
        if (tank[2].laizer == 0){
            for (int i = 0; i < 5; i++) {
                if (tank[2].has == true && tank[2].tir[i].por == false) {
                    tank[2].tir[i].por = true;
                    tank[2].tir[i].zavtir = tank[2].zav;
                    tank[2].tir[i].x = tank[2].x + 1.5 * r * cos(tank[2].zav);
                    tank[2].tir[i].y = tank[2].y - 1.5 * r * sin(tank[2].zav);
                    *flagtir2 = 1;
                    break;
                }
            }
        }
        else{
            if(*ss==0){
                tank[2].tir[5].x = tank[2].x + 1.5 * r * cos(tank[2].zav);
                tank[2].tir[5].y = tank[2].y - 1.5 * r * sin(tank[2].zav);
                tank[2].tir[5].zavtir=tank[2].zav;
                tank[2].tir[5].por = true;
                *ss=1;
                *flagtir2 = 1;
            }
            else{
                for(int i=6;i<15;i++){
                    tank[2].tir[i].x=tank[2].tir[5].x;tank[2].tir[i].y=tank[2].tir[5].y;
                    tank[2].tir[i].zavtir=(2*3.14/9)*i;
                    tank[2].tir[i].por=true;
                }
                tank[2].tir[5].por=false;
                *ss=0;
                tank[2].laizer =0;
                *flagtir2 = 1;
            }

        }
    }
    if( currentKeyStates[ SDL_SCANCODE_UP ]&&cheksar(map, tank[1].x + step * cos(tank[1].zav),tank[1].y - step * sin(tank[1].zav),snake_radius)==0/*&&divarkhor(map,tank[1].x + step * cos(tank[1].zav),tank[1].y - step * sin(tank[1].zav),r)==0)&&saresh(tank[1].x + step * cos(tank[1].zav),tank[1].y - step * sin(tank[1].zav),tank[1].x + step * cos(tank[1].zav)+1.5*r*cos(tank[1].zav),tank[1].y - step * sin(tank[1].zav)-1.5*r*sin(tank[1].zav),map)==0*/)
    {
        //printf("salam");
        if(divarkhor(map,tank[1].x + step * cos(tank[1].zav),tank[1].y - step * sin(tank[1].zav),r)==0) {
            tank[1].y -= step * sin(tank[1].zav);
            tank[1].x += step * cos(tank[1].zav);
        }
        if (divarkhor(map, tank[1].x + step * cos(tank[1].zav), tank[1].y - step * sin(tank[1].zav), r) == 1) {

            if ((0 <= sin(tank[1].zav) && sin(tank[1].zav) <= 1 && cos(tank[1].zav) >= 0 &&
                 cos(tank[1].zav) <= 1) ||
                (-1 <= sin(tank[1].zav) && sin(tank[1].zav) < 0 && cos(tank[1].zav) >= -1 &&
                 cos(tank[1].zav) <= 0)) {
//               tank[1].y -= step * sin(tank[1].zav);
                tank[1].zav += ( (megh)/2);

            }
                // if ((0 < sin(tank[1].zav) && sin(tank[1].zav) <= 1 && -1 <= cos(tank[1].zav) &&cos(tank[1].zav) <= 0) ||(-1 <= sin(tank[1].zav) && sin(tank[1].zav) <= 0 && 0 <= cos(tank[1].zav) &&cos(tank[1].zav) <= 1)) {
                //  tank[1].y -= step * sin(tank[1].zav);
            else{
                tank[1].zav -= (megh/2);
            }
        }
        if (divarkhor(map, tank[1].x + step * cos(tank[1].zav), tank[1].y - step * sin(tank[1].zav), r) == 2) {
//            if(-1<cos(tank[1].zav)&&cos(tank[1].zav)<0){
//                tank[1].x += step * cos(tank[1].zav);
//            }
//            if((0<cos(tank[1].zav)&&cos(tank[1].zav)<1)){
//                tank[1].x += step * cos(tank[1].zav);
//            }
            if ((0 <= sin(tank[1].zav) && sin(tank[1].zav) <= 1 && cos(tank[1].zav) >= 0 &&
                 cos(tank[1].zav) <= 1) ||
                (-1 <= sin(tank[1].zav) && sin(tank[1].zav) <= 0 && cos(tank[1].zav) >= -1 &&
                 cos(tank[1].zav) <= 0)) {
//               tank[1].y -= step * sin(tank[1].zav);
                tank[1].zav -= (megh/2);

            }
                // if ((0 <= sin(tank[1].zav) && sin(tank[1].zav) <= 1 && -1 <= cos(tank[1].zav) &&cos(tank[1].zav) <= 0) ||(-1 <= sin(tank[1].zav) && sin(tank[1].zav) <= 0 && 0 <= cos(tank[1].zav) &&cos(tank[1].zav) <= 1)) {
                //  tank[1].y -= step * sin(tank[1].zav);
            else{
                tank[1].zav += (megh/2);
            }

        }

    }
    if( currentKeyStates[ SDL_SCANCODE_DOWN ]&&divarkhor(map, tank[1].x -step*cos(tank[1].zav), tank[1].y +step*sin(tank[1].zav),r)==0 &&cheksar(map, tank[1].x - step * cos(tank[1].zav),tank[1].y + step * sin(tank[1].zav),snake_radius)==0)
    {
        tank[1].y +=step*sin(tank[1].zav);
        tank[1].x -=step*cos(tank[1].zav);
    }
    if( currentKeyStates[ SDL_SCANCODE_LEFT ] )
    {
        tank[1].zav+=megh;
    }
    if( currentKeyStates[ SDL_SCANCODE_RIGHT ] )
    {
        tank[1].zav-=megh;
    }
    if(currentKeyStates[ SDL_SCANCODE_M ]==0){
        *flagtir=0;
    }
    if(currentKeyStates[ SDL_SCANCODE_M ]&&*flagtir==0){
        if (tank[1].laizer == 0&&tank[1].lazerasli == 0){
            for (int i = 0; i < 5; i++) {
                if (tank[1].has == true && tank[1].tir[i].por == false) {
                    tank[1].tir[i].por = true;
                    tank[1].tir[i].zavtir = tank[1].zav;
                    tank[1].tir[i].x = tank[1].x + 1.5 * r * cos(tank[1].zav);
                    tank[1].tir[i].y = tank[1].y - 1.5 * r * sin(tank[1].zav);
                    *flagtir = 1;
                    break;
                }
            }
        }
        if(tank[1].lazerasli&&tank[1].laizer==0){
            *lazerbezan1=1;
        }
        if(tank[1].laizer&&tank[1].lazerasli==0){
            if(*s==0){
                tank[1].tir[5].x = tank[1].x + 1.5 * r * cos(tank[1].zav);
                tank[1].tir[5].y = tank[1].y - 1.5 * r * sin(tank[1].zav);
                tank[1].tir[5].zavtir=tank[1].zav;
                tank[1].tir[5].por = true;
                *s=1;
                *flagtir = 1;
            }
            else{
                for(int i=6;i<15;i++){
                    tank[1].tir[i].x=tank[1].tir[5].x;tank[1].tir[i].y=tank[1].tir[5].y;
                    tank[1].tir[i].zavtir=(2*3.14/9)*i;
                    tank[1].tir[i].por=true;
                }
                tank[1].tir[5].por=false;
                *s=0;
                tank[1].laizer =0;
                *flagtir = 1;
            }

        }
    }
}
int handleEvents() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT)
            return 1;
        if(event.type==SDL_KEYDOWN){
            if(event.key.keysym.sym==SDLK_RETURN)
                return 2;
        }
        if(event.type==SDL_KEYDOWN){
                    if(event.key.keysym.sym==SDLK_a) {
                        return 3;
            }
        }

    }
}
//int salam(){
//    SDL_Event event;
//    while(SDL_PollEvent(&event)){
//        if(event.type==SDL_KEYDOWN){
//            if(event.key.keysym.sym==SDLK_1)return 1;
//            if(event.key.keysym.sym==SDLK_1)a[1]=*n;
//            if(event.key.keysym.sym==SDLK_2)a[2]=*n;
//            if(event.key.keysym.sym==SDLK_3)a[3]=*n;
//            if(event.key.keysym.sym==SDLK_4)a[4]=*n;
//            if(event.key.keysym.sym==SDLK_5)a[5]=*n;
//            if(event.key.keysym.sym==SDLK_6)a[6]=*n;
//            if(event.key.keysym.sym==SDLK_7)a[7]=*n;
//            if(event.key.keysym.sym==SDLK_8)a[8]=*n;
//            if(event.key.keysym.sym==SDLK_9)a[9]=*n;
//            if(event.key.keysym.sym==SDLK_0)a[0]=*n;
//        }
//    }
//}