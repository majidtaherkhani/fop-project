#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <SDL.h>
#include <SDL2_gfxPrimitives.h>
#include "view.h"
#include "structha.h"
#include "naghsheha.h"
#include "harekat.h"

const int step = 5;
const double megh=2*3.14/90;

int handleEvents() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT)
            return 1;
    }
}



#ifdef main
#undef main
#endif

int main(int argc, char* argv[]) {
    Map map;
    tirs tir[5];
    tanks tank;
    int flagtir=0;
    tank.x = 50;
    tank.y = 50;
    tank.zav=0;
    double snake_radius = 20;
    for(int i=0;i<5;i++){
        tir[i].por=false;
        tir[i].zaman=0;
    }

    int snake_score = 0;
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window* window = SDL_CreateWindow("workshop", 20, 20, 600, 600, SDL_WINDOW_OPENGL);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    int begining_of_time = SDL_GetTicks();
    const double FPS = 30;
    while (1) {
        int start_ticks = SDL_GetTicks();

        if (handleEvents() ) break;
        SDL_Event event;

        SDL_SetRenderDrawColor(renderer, 255,255, 255, 255);
        SDL_RenderClear(renderer);
        khoondan(&map,"C:\\Users\\majid\\Desktop\\majijjjj.txt");
        rasm(&map,renderer);

        klid(snake_radius,tir,&tank,&flagtir,step,map);

        int rt= snake_radius / 4;
        for(int i=0;i<5;i++){
            if(tir[i].por==true){
                if((tir[i].y-step*sin(tir[i].zavtir)<rt||tir[i].y-step*sin(tir[i].zavtir)>600-rt)||divarkhor(map, tir[i].x + step * cos(tir[i].zavtir), tir[i].y - step * sin(tir[i].zavtir),snake_radius / 4)==2){
                    tir[i].zavtir=-tir[i].zavtir;
                }
                else if(tir[i].x+step*cos(tir[i].zavtir)<rt|| tir[i].x+step*cos(tir[i].zavtir)>600+rt||divarkhor(map, tir[i].x + step * cos(tir[i].zavtir), tir[i].y - step * sin(tir[i].zavtir),snake_radius / 4)==1){
                    tir[i].zavtir=-tir[i].zavtir-3.14;
                }
                tir[i].y -= step * sin(tir[i].zavtir);
                tir[i].x += step * cos(tir[i].zavtir);
                filledCircleRGBA(renderer, tir[i].x, tir[i].y, snake_radius / 4, 0, 100, 100, 255);
                tir[i].zaman++;
            }
        }
        for(int i=0;i<5;i++){
            if(tir[i].zaman==200){
                tir[i].por=false;
                tir[i].zaman=0;
            }

        }


        filledCircleRGBA(renderer, tank.x, tank.y, snake_radius, 0, 100, 100, 255);
        thickLineRGBA(renderer,tank.x,tank.y,2*snake_radius*cos(tank.zav)+tank.x,tank.y-2*snake_radius*sin(tank.zav),5, 0, 100, 100, 255);
        char* buffer = malloc(sizeof(char) * 50);
        sprintf(buffer, "score: %d   elapsed time: %dms", snake_score,  start_ticks -begining_of_time);
        printf("%s", buffer);
        stringRGBA(renderer, 5, 5, buffer, 0, 0, 0, 255);
        SDL_RenderPresent(renderer);

        while (SDL_GetTicks() - start_ticks < 1000 / FPS);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}