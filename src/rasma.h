//
// Created by majid on 12/23/2018.
//

#ifndef PROJECT_RASMA_H
#define PROJECT_RASMA_H

#include "structha.h"
#include <SDL2_gfxPrimitives.h>
void rasmap(SDL_Renderer *renderer,Map map);
void rasmenu(SDL_Renderer *renderer,int n,int a);

void rasmtir(double snake_radiuse,tanks tank[],SDL_Renderer *renderer,int step,Map map);
jatank(int adad ,tanks tank[], double tool, double rasm);
void jaselah(selahs *sela,double tool,double arz);
#endif //PROJECT_RASMA_H
