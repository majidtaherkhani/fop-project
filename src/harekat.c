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

int cheksar(Map map,double x,double y, double r){
    r-=1;
    for(int i=0;i<map.tedad;i++){
        if((((map.divar[i].x1-x)*(map.divar[i].x1-x)+(map.divar[i].y1-y)*(map.divar[i].y1-y))<r*r)||((map.divar[i].x2-x)*(map.divar[i].x2-x)+(map.divar[i].y2-y)*(map.divar[i].y2-y)<r*r)){
            return 1;
        }
    }
    return 0;
}
void klid(double snake_radius,tanks tank[],int *flagtir,int step,Map map,int *flagtir2){
    double r=snake_radius;
    const double megh=2*M_PI/90;
    const Uint8* currentKeyStates = SDL_GetKeyboardState( NULL );
    if( currentKeyStates[ SDL_SCANCODE_UP ]&&cheksar(map, tank[1].x + step * cos(tank[1].zav),tank[1].y - step * sin(tank[1].zav),snake_radius)==0)/*&&divarkhor(map,tank[1].x + step * cos(tank[1].zav),tank[1].y - step * sin(tank[1].zav),r)==0/* &&saresh(tank[1].x + step * cos(tank[1].zav),tank[1].y - step * sin(tank[1].zav),tank[1].x + step * cos(tank[1].zav)+2*r*cos(tank[1].zav),tank[1].y - step * sin(tank[1].zav)-2*r*sin(tank[1].zav),map)==0*/
    {
        if(divarkhor(map,tank[1].x + step * cos(tank[1].zav),tank[1].y - step * sin(tank[1].zav),r)==0) {
            tank[1].y -= step * sin(tank[1].zav);
            tank[1].x += step * cos(tank[1].zav);
        }
        if(divarkhor(map,tank[1].x + step * cos(tank[1].zav),tank[1].y - step * sin(tank[1].zav),r)==1){
            printf("salam");
            if(0<sin(tank[1].zav)&&sin(tank[1].zav)<1){
               tank[1].y -= step * sin(tank[1].zav);
            }
            if(-1<sin(tank[1].zav)&&sin(tank[1].zav)<0){
                tank[1].y -= step * sin(tank[1].zav);
            }
        }
        if(divarkhor(map,tank[1].x + step * cos(tank[1].zav),tank[1].y - step * sin(tank[1].zav),r)==2){
            if(-1<cos(tank[1].zav)&&cos(tank[1].zav)<0){
                tank[1].x += step * cos(tank[1].zav);
            }
            if((0<cos(tank[1].zav)&&cos(tank[1].zav)<1)){
                tank[1].x += step * cos(tank[1].zav);
            }
        }
    }
    if( currentKeyStates[ SDL_SCANCODE_DOWN ]&&cheksar(map, tank[1].x - step * cos(tank[1].zav),tank[1].y + step * sin(tank[1].zav),snake_radius)==0/*&&divarkhor(map, tank[1].x -step*cos(tank[1].zav), tank[1].y +step*sin(tank[1].zav),r)==0/* &&saresh(tank[1].x - step * cos(tank[1].zav),tank[1].y + step * sin(tank[1].zav),tank[1].x - step * cos(tank[1].zav)+2*r*cos(tank[1].zav),tank[1].y + step * sin(tank[1].zav)-2*r*sin(tank[1].zav),map)==0*/)
    {
        if(divarkhor(map, tank[1].x -step*cos(tank[1].zav), tank[1].y +step*sin(tank[1].zav),r)==0) {
            tank[1].y += step * sin(tank[1].zav);
            tank[1].x -= step * cos(tank[1].zav);
        }
        if(divarkhor(map, tank[1].x -step*cos(tank[1].zav), tank[1].y +step*sin(tank[1].zav),r)){

        }
        if(divarkhor(map, tank[1].x -step*cos(tank[1].zav), tank[1].y +step*sin(tank[1].zav),r)==2){

        }
    }
    if( currentKeyStates[ SDL_SCANCODE_LEFT ]/* &&saresh(tank[1].x,tank[1].y,tank[1].x+2*r*cos(tank[1].zav+megh),tank[1].y-2*r*sin(tank[1].y+megh),map)==0*/)
    {
        tank[1].zav+=megh;
    }
    if( currentKeyStates[ SDL_SCANCODE_RIGHT ]/*&&saresh(tank[1].x,tank[1].y,tank[1].x+2*r*cos(tank[1].zav-megh),tank[1].y-2*r*sin(tank[1].y-megh),map)==0*/ )
    {
        tank[1].zav-=megh;
    }
    if(currentKeyStates[ SDL_SCANCODE_M ]==0){
        *flagtir=0;
    }
    if(currentKeyStates[ SDL_SCANCODE_M ]&&*flagtir==0){
        for(int i=0;i<5;i++){
            if(tank[1].has==true&&tank[1].tir[i].por==false){
                tank[1].tir[i].por=true;
                tank[1].tir[i].zavtir=tank[1].zav;
                tank[1].tir[i].x=tank[1].x+2*r*cos(tank[1].zav);
                tank[1].tir[i].y=tank[1].y-2*r*sin(tank[1].zav);
                *flagtir=1;
                break;
            }
        }
    }
    if( currentKeyStates[ SDL_SCANCODE_W ]&& cheksar(map, tank[2].x + step * cos(tank[2].zav),tank[2].y - step * sin(tank[2].zav),snake_radius)==0){
        if(divarkhor(map,tank[2].x + step * cos(tank[2].zav),tank[2].y - step * sin(tank[2].zav),r)==0) {
            tank[2].y -= step * sin(tank[2].zav);
            tank[2].x += step * cos(tank[2].zav);
        }
    if(divarkhor(map,tank[2].x + step * cos(tank[2].zav),tank[2].y - step * sin(tank[2].zav),r)==1){
        if(0<sin(tank[2].zav)&&sin(tank[2].zav)<1){
            tank[2].y -= step * sin(tank[2].zav);
        }
        if(-1<sin(tank[2].zav)&&sin(tank[2].zav)<0){
            tank[2].y -= step * sin(tank[2].zav);
        }
    }
    if(divarkhor(map,tank[2].x + step * cos(tank[2].zav),tank[2].y - step * sin(tank[2].zav),r)==2){
        if(-1<cos(tank[2].zav)&&cos(tank[2].zav)<0){
            tank[2].x += step * cos(tank[2].zav);
        }
        if((0<cos(tank[2].zav)&&cos(tank[2].zav)<1)){
            tank[2].x += step * cos(tank[2].zav);
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
        for(int i=0;i<5;i++){
            if(tank[2].has==true&&tank[2].tir[i].por==false){
                tank[2].tir[i].por=true;
                tank[2].tir[i].zavtir=tank[2].zav;
                tank[2].tir[i].x=tank[2].x+2*r*cos(tank[2].zav);
                tank[2].tir[i].y=tank[2].y-2*r*sin(tank[2].zav);
                *flagtir2=1;
                break;
            }
        }
    }
}
int handleEvents() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT)
            return 1;
    }
}
