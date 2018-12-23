//
// Created by majid on 12/23/2018.
//
#include <SDL2_gfxPrimitives.h>
#include "structha.h"
#include <stdbool.h>
#include "structha.h"
#include "naghsheha.h"

void klid(int snake_radius,tirs tir[],tanks *tank,int *flagtir,int step,Map map){
    int r=snake_radius;
    const double megh=2*3.14/90;
    const Uint8* currentKeyStates = SDL_GetKeyboardState( NULL );
    if( currentKeyStates[ SDL_SCANCODE_UP ]&&((tank->y)-step*sin(tank->zav))>=r && (tank->y)-step*sin(tank->zav)<=600-r &&(tank->x)+step * cos(tank->zav)>=r&&(tank->x)+step * cos(tank->zav)<=600+r&&divarkhor(map,tank->x + step * cos(tank->zav),tank->y - step * sin(tank->zav),r)==0 )
    {
        tank->y -= step * sin(tank->zav);
        tank->x += step * cos(tank->zav);

    }
    if( currentKeyStates[ SDL_SCANCODE_DOWN ]&&(tank->y)+step*sin(tank->zav)>=r&&(tank->y)+step*sin(tank->zav)<=600-r&&(tank->x)-step*cos(tank->zav)>=r&&(tank->x)-step*cos(tank->zav)<=600+r&&divarkhor(map, tank->x -step*cos(tank->zav), tank->y +step*sin(tank->zav),r)==0 )
    {
        tank->y +=step*sin(tank->zav);
        tank->x -=step*cos(tank->zav);
    }
    if( currentKeyStates[ SDL_SCANCODE_LEFT ] )
    {
        tank->zav+=megh;
    }
    if( currentKeyStates[ SDL_SCANCODE_RIGHT ] )
    {
        tank->zav-=megh;
    }
    if(currentKeyStates[ SDL_SCANCODE_M ]==0){
        *flagtir=0;
    }
    if(currentKeyStates[ SDL_SCANCODE_M ]&&*flagtir==0){
        for(int i=0;i<5;i++){
            if(tir[i].por==false){
                tir[i].por=true;
                tir[i].zavtir=tank->zav;
                tir[i].x=tank->x;
                tir[i].y=tank->y;
                *flagtir=1;
                break;
            }
        }
    }
}