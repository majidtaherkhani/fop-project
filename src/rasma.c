//
// Created by majid on 12/23/2018.
//

#include "rasma.h"
#include "structha.h"
#include <SDL2_gfxPrimitives.h>
#include "naghsheha.h"
void rasmtir(double snake_radius,tanks tank[],SDL_Renderer *renderer,int step,Map map){
    double rt= snake_radius / 4;
    for(int j=1;j<3;j++) {
        for (int i = 0; i < 5; i++) {
            if (tank[j].tir[i].por == true) {
                if ((tank[j].tir[i].y - step * sin(tank[j].tir[i].zavtir) < rt || tank[j].tir[i].y - step * sin(tank[j].tir[i].zavtir) > 600 - rt) ||divarkhor(map, tank[j].tir[i].x + step * cos(tank[j].tir[i].zavtir), tank[j].tir[i].y - step * sin(tank[j].tir[i].zavtir),snake_radius / 4) == 2) {
                    tank[j].tir[i].zavtir = -tank[j].tir[i].zavtir;
                } else if (tank[j].tir[i].x + step * cos(tank[j].tir[i].zavtir) < rt ||tank[j].tir[i].x + step * cos(tank[j].tir[i].zavtir) > 600 + rt ||divarkhor(map, tank[j].tir[i].x + step * cos(tank[j].tir[i].zavtir), tank[j].tir[i].y - step * sin(tank[j].tir[i].zavtir),snake_radius / 4) == 1) {
                    tank[j].tir[i].zavtir = -tank[j].tir[i].zavtir - 3.14;
                }
                tank[j].tir[i].y -= step * sin(tank[j].tir[i].zavtir);
                tank[j].tir[i].x += step * cos(tank[j].tir[i].zavtir);
                filledCircleRGBA(renderer, tank[j].tir[i].x, tank[j].tir[i].y, snake_radius / 4, 0, 100, 100, 255);tank[j].tir[i].zaman++;
            }
        }
    }
}