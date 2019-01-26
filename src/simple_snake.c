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
#include "rasma.h"
#include <time.h>
#include <SDL_test_images.h>
#include <SDL2_imageFilter.h>

const int step = 5;
const double megh=2*3.14/90;
#ifdef main
#undef main
#endif
int tank1score = 0;
int tank2score = 0;
int main(int argc, char* argv[]) {
    int flagasli=1;

    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window *window = SDL_CreateWindow("workshop", 100, 100, 750, 500, SDL_WINDOW_OPENGL);
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);


    while(1) {
        srand(time(NULL));
        Map map;
        double toolran = rand() % 100 + 500;
        double arzran = rand() % 100 + 300;

        box khoone[5][5][5];
        tanks tank[3];
        int flagtir = 0;
        int flagtir2 = 0;

        tank[1].zav = rand() % 20;
        tank[2].zav = rand() % 20;
        tank[1].has = true;
        tank[2].has = true;
        double snake_radius = 12;
        for (int j = 0; j < 5; j++) {
            for (int i = 0; i < 5; i++) {
                tank[j].tir[i].por = false;
                tank[j].tir[i].zaman = 0;
            }
        }
//        SDL_Init(SDL_INIT_VIDEO);
//        SDL_Window *window = SDL_CreateWindow("workshop", 100, 100,toolran, toolran, SDL_WINDOW_OPENGL);
//        SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

        //int snake_score=0;

        int begining_of_time = SDL_GetTicks();
        const double FPS = 30;
        maprand(1, khoone);
        maprand(2, khoone);
        maprand(3, khoone);
        maprand(4, khoone);
        map.tedad = aval(khoone, &map, toolran, arzran);

        jatank(1, tank, toolran, arzran);
        jatank(2, tank, toolran, arzran);
        while (1) {
            int start_ticks = SDL_GetTicks();

            if (handleEvents() == 1) {
                flagasli=0;
                break;
            }
            SDL_Event event;

            SDL_SetRenderDrawColor(renderer, 255,255, 255, 255);
            SDL_RenderClear(renderer);

            for (int j = 1; j < 3; j++) {
                for (int i = 0; i < 5; i++) {
                    if (tank[j].tir[i].zaman == 200) {
                        tank[j].tir[i].por = false;
                        tank[j].tir[i].zaman = 0;
                    }
                }
            }
            for (int i = 1; i < 3; i++) {
                for (int j = 0; j < 5; j++) {
                    if (tank[i].tir[j].por == true &&tank[1].has == true && (tank[i].tir[j].x - tank[1].x) * (tank[i].tir[j].x - tank[1].x) +(tank[i].tir[j].y - tank[1].y) * (tank[i].tir[j].y - tank[1].y) <=25 / 16 * snake_radius * snake_radius) {
                        tank[1].has = false;
                        tank[i].tir[j].por = false;
                    }
                    if ( tank[i].tir[j].por == true &&tank[2].has == true &&(tank[i].tir[j].x - tank[2].x) * (tank[i].tir[j].x - tank[2].x) +(tank[i].tir[j].y - tank[2].y) * (tank[i].tir[j].y - tank[2].y) <=25 / 16 * snake_radius * snake_radius) {
                        tank[2].has = false;
                        tank[i].tir[j].por = false;
                    }
                }
            }
            //khoondan(&map);
            // rasm(&map,renderer);
            rasja(khoone, renderer, &map, toolran, arzran);


            klid(snake_radius, tank, &flagtir, step, map, &flagtir2);

            rasmtir(snake_radius, tank, renderer, step, map);
            if (tank[1].has == true) {
                filledCircleRGBA(renderer, tank[1].x, tank[1].y, snake_radius, 0, 100, 100, 255);
                thickLineRGBA(renderer, tank[1].x, tank[1].y, 1.5 * snake_radius * cos(tank[1].zav) + tank[1].x,tank[1].y - 1.5 * snake_radius * sin(tank[1].zav), 5, 0, 100, 100, 255);
            }
            if (tank[2].has == true) {
                filledCircleRGBA(renderer, tank[2].x, tank[2].y, snake_radius, 100, 0, 100, 255);
                thickLineRGBA(renderer, tank[2].x, tank[2].y, 1.5 * snake_radius * cos(tank[2].zav) + tank[2].x,tank[2].y - 1.5 * snake_radius * sin(tank[2].zav), 5, 100, 0, 100, 255);
            }
            if (tank[1].has == false || tank[2].has == false){
                if(tank[1].has == false){
                    tank2score++;
                    break;
                }
                tank1score++;
                break;
            }
           // SDL_Surface *image=SDL_LoadBMP("C:\\Users\\majid\\Desktop\\IMG_20180121_0022.jpg");
            //SDL_Texture * texture=SDL_CreateTextureFromSurface(renderer,image);

            char *buffer = malloc(sizeof(char) * 50);
            char *biffer = malloc(sizeof(char) * 50);
            sprintf(buffer, "blue: %d "/* elapsed time: %dms"*/, tank1score/*, start_ticks - begining_of_time*/);
            sprintf(biffer, "violet: %d " /*elapsed time: %dms*/, tank2score/*, start_ticks - begining_of_time*/);

            //printf("%s", buffer);
            stringRGBA(renderer, 200, 450, buffer, 0, 100, 100, 255);
            stringRGBA(renderer,500,450,biffer,100,0,100,255);
            //SDL_RenderCopy(renderer,texture,NULL,NULL);
            SDL_RenderPresent(renderer);

            while (SDL_GetTicks() - start_ticks < 1000 / FPS);
        }
        if (!flagasli||tank1score==20||tank2score==20)break;
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    // if (handleEvents() == 1) break;
    //SDL_Delay(150);
    // }
//    SDL_DestroyRenderer(renderer);
//    SDL_DestroyWindow(window);
//    SDL_Quit();
    return 0;
}
