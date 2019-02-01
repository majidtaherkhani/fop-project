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
#include "saveha.h"
const int step = 5;
jijooreye=2;
int bayghosh=0;
int biroon=30;
double x11,y11;
double zav11;
int chandomish=1;
int aaa[11];
int hava=0;
int a=-1,b=-1;
int nomre=0;
int akharinharekat=0;
int lazerbezan1=0,lazerbezan2=0;
int flagup=1,flagdan=1;int flagup1=1,flagdan1=1;
const double megh=2*3.14/90;
#ifdef main
#undef main
#endif
int selahas=0;
int s=0;
int ss=0;
int zamanselah=0;
int tank1score = 0;
int tank2score = 0;
int main(int argc, char* argv[]) {
    int tedade = 0;
    int w = 1;
    int shomareme = 1;
    int flagasliman = 0;
    //for(int i=0;i<20;i++)a[i]=false;
    int ttt = 0;
    int flagasli = 1;
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window *window = SDL_CreateWindow("workshop", 100, 100, 750, 500, SDL_WINDOW_OPENGL);
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);


    ssave saveha[100];
    selahs selah;
    lazers lazer;
    lazer.has = 0;
    selah.has = 0;
    int tedadsave = 0;
    int b = 0;
    while (1) {
        if (handleEvents() == 2) {
            break;
        }
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderClear(renderer);
        rasmenu(renderer, jijooreye, 1);
        klidmenu(&flagup1, &flagdan1, &jijooreye, 1);
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                SDL_DestroyRenderer(renderer);
                SDL_DestroyWindow(window);
                SDL_Quit();
                return 0;
            }
            if (event.type == SDL_KEYDOWN) {
                if (event.key.keysym.sym == SDLK_RETURN) {
                    if (jijooreye == 4) {
                        SDL_DestroyRenderer(renderer);
                        SDL_DestroyWindow(window);
                        SDL_Quit();
                        return 0;
                    }
                    if (jijooreye == 2) {
                        b = 1;
                    }
                    if(jijooreye==3){
                        bayghosh=1;
                        b=1;
                    }
                }
            }
        }
        if (b == 1)break;

        SDL_RenderPresent(renderer);
    }
    int mmm=0,fff=0;
    while (1) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_KEYDOWN) {
                if (event.key.keysym.sym == SDLK_m) {
                    mmm=1;

                }
                if (event.key.keysym.sym == SDLK_f)fff=1;
            }
        }
        if (mmm==1&&fff==1) {
            break;
        }
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderClear(renderer);
        stringRGBA(renderer, 200, 200, "blue", 0, 0, 0, 255);
        stringRGBA(renderer, 400, 200, "violet", 0, 0, 0, 255);
        thickLineRGBA(renderer, 180, 250, 200, 250, 20, 100, 100, 100, 255);
        thickLineRGBA(renderer, 205, 250, 225, 250, 20, 100, 100, 100, 255);
        thickLineRGBA(renderer, 230, 250, 250, 250, 20, 100, 100, 100, 255);
        thickLineRGBA(renderer, 205, 225, 225, 225, 20, 100, 100, 100, 255);
        thickLineRGBA(renderer, 150, 225, 170, 225, 20, 100, 100, 100, 255);
        stringRGBA(renderer, 190, 240, "<", 0, 0, 0, 255);
        stringRGBA(renderer, 215, 240, "", 0, 0, 0, 255);
        stringRGBA(renderer, 240, 240, ">", 0, 0, 0, 255);
        stringRGBA(renderer, 215, 215, "^", 0, 0, 0, 255);
        stringRGBA(renderer, 160, 215, "M", 0, 0, 0, 255);
        //stringRGBA(rendere,)

        thickLineRGBA(renderer, 380, 250, 400, 250, 20, 100, 100, 100, 255);
        thickLineRGBA(renderer, 405, 250, 425, 250, 20, 100, 100, 100, 255);
        thickLineRGBA(renderer, 430, 250, 450, 250, 20, 100, 100, 100, 255);
        thickLineRGBA(renderer, 455, 250, 475, 250, 20, 100, 100, 100, 255);
        thickLineRGBA(renderer, 405, 225, 425, 225, 20, 100, 100, 100, 255);
        stringRGBA(renderer, 390, 240, "A", 0, 0, 0, 255);
        stringRGBA(renderer, 415, 240, "S", 0, 0, 0, 255);
        stringRGBA(renderer, 440, 240, "D", 0, 0, 0, 255);
        stringRGBA(renderer, 465, 240, "F", 0, 0, 0, 255);
        stringRGBA(renderer, 415, 215, "W", 0, 0, 0, 255);
//        stringRGBA(renderer,180,220,"emtyaz nahayi ra vared konid",0,0,0,255);
        SDL_RenderPresent(renderer);

    }
    int cs = 0;
    int nn = 1;
    while (1) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_KEYDOWN) {
                if (event.key.keysym.sym == SDLK_RETURN) {
                    cs = 1;
                }
            }
            if (event.type == SDL_KEYDOWN) {
                if (event.key.keysym.sym == SDLK_1)aaa[1] = nn;
                if (event.key.keysym.sym == SDLK_2)aaa[2] = nn;
                if (event.key.keysym.sym == SDLK_3)aaa[3] = nn;
                if (event.key.keysym.sym == SDLK_4)aaa[4] = nn;
                if (event.key.keysym.sym == SDLK_5)aaa[5] = nn;
                if (event.key.keysym.sym == SDLK_6)aaa[6] = nn;
                if (event.key.keysym.sym == SDLK_7)aaa[7] = nn;
                if (event.key.keysym.sym == SDLK_8)aaa[8] = nn;
                if (event.key.keysym.sym == SDLK_9)aaa[9] = nn;
                if (event.key.keysym.sym == SDLK_0)aaa[0] = nn;
                nn++;
            }
        }
        if (cs == 1)break;
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderClear(renderer);
        stringRGBA(renderer, 260, 200, "emtyaz nahayi ra vared konid", 0, 0, 0, 255);
        SDL_RenderPresent(renderer);

    }
    for (int i = 0; i < 10; i++) {
        if (aaa[i] == 1)nomre += i;
        if (aaa[i] == 2)nomre += i * 10;
        if (aaa[i] == 3)nomre += i * 100;
    }
    printf("%d", nomre);
    while (1) {
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
            for (int i = 0; i < 15; i++) {
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
        if(bayghosh==0) {
            maprand(1, khoone);
            maprand(2, khoone);
            maprand(3, khoone);
            maprand(4, khoone);
            map.tedad = aval(khoone, &map, toolran, arzran);

            jatank(1, tank, toolran, arzran);
            jatank(2, tank, toolran, arzran);
            selah.has = 0;
            tank[1].laizer = 0;
            tank[2].laizer = 0;
            tank[1].lazerasli = 0;
            tank[2].lazerasli = 0;
        }
        else{
            bekhoonesh(&map,tank,&tank1score,&tank2score,&selah);
        }
        while (1) {
            int start_ticks = SDL_GetTicks();
            if (savefeshar()) {

                savekon(saveha, map, tank, tank1score, tank2score);
                //tedadsave++;
            }
            if (savejra()) {

                jabejayi(saveha, &map, tank, &tank1score, &tank2score);

            }

            if (handleEvents() == 1) {
                flagasli = 0;
                break;
            }
            if (menu()) {
                w = 0;
            }
            if (w == 0 && menu() == 0) {
                w = 1;
                tedade++;
            }
            if (tedade % 2 == 0) {
                ttt = 0;

            } else ttt = 1;
            SDL_Event event;
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            SDL_RenderClear(renderer);
            if (ttt) {
                rasmenu(renderer, shomareme, 2);
                klidmenu(&flagup, &flagdan, &shomareme, 2);
                savina(&flagasli, &shomareme, &tedade, saveha, &map, tank, &tank1score, &tank2score,&selah);
                if (flagasli == 0)break;
            } else {
                if (selah.zaman == 290) {
                    selah.zaman = 0;
                    selah.has = 1;
                    jaselah(&selah, toolran, arzran);
                }
                if (!selah.has) {
                    selah.zaman++;
                }
                if (selah.has) {
                    filledCircleRGBA(renderer, selah.x, selah.y, 8, 50, 50, 50, 255);
                }
                if (lazer.zaman == 100000000) {
                    lazer.zaman = 0;
                    lazer.has = 1;
                    jaselah(&lazer, toolran, arzran);
                }
                if (!lazer.has) {
                    lazer.zaman++;
                }
                if (lazer.has) {

                    filledCircleRGBA(renderer, lazer.x, lazer.y, 8, 250, 50, 50, 255);
                }

                for (int j = 1; j < 3; j++) {
                    for (int i = 0; i < 5; i++) {
                        if (tank[j].tir[i].zaman == 200) {
                            tank[j].tir[i].por = false;
                            tank[j].tir[i].zaman = 0;
                        }
                    }
                }
//                for(int j=1;j<3;j++) {
//                    for (int i = 6; i < 11; i++) {
//                        if (divarkhor(map,tank[j].tir[i].x,tank[j].tir[i].y,snake_radius/4)==1||divarkhor(map,tank[j].tir[i].x,tank[j].tir[i].y,snake_radius/4)==2||divarkhor(map,tank[j].tir[i].x,tank[j].tir[i].y,snake_radius/4)==5){
//                            tank[j].tir[i].por=false;
//                        }
//                    }
//                }
                for (int i = 1; i < 3; i++) {
                    for (int j = 0; j < 15; j++) {
                        if (tank[i].tir[j].por == true && tank[1].has == true &&
                            (tank[i].tir[j].x - tank[1].x) * (tank[i].tir[j].x - tank[1].x) +
                            (tank[i].tir[j].y - tank[1].y) * (tank[i].tir[j].y - tank[1].y) <=
                            25 / 16 * snake_radius * snake_radius) {
                            tank[1].has = false;
                            tank[i].tir[j].por = false;
                        }
                        if (tank[i].tir[j].por == true && tank[2].has == true &&
                            (tank[i].tir[j].x - tank[2].x) * (tank[i].tir[j].x - tank[2].x) +
                            (tank[i].tir[j].y - tank[2].y) * (tank[i].tir[j].y - tank[2].y) <=
                            25 / 16 * snake_radius * snake_radius) {
                            tank[2].has = false;
                            tank[i].tir[j].por = false;
                        }
                    }
                }
                //khoondan(&map);
                // rasm(&map,renderer);
                //rasja(khoone, renderer, &map, toolran, arzran);
                rasmap(renderer, map);
                klid(snake_radius, tank, &flagtir, step, map, &flagtir2, &s, &ss, &lazerbezan1, &lazerbezan2);
                if (tank[1].has && selah.has &&
                    (tank[1].x - selah.x) * (tank[1].x - selah.x) + (tank[1].y - selah.y) * (tank[1].y - selah.y) <
                    400) {
                    tank[1].laizer = 1;
                    // tank[1].tir[5].por=true;
                    selah.has = 0;
                }
                if (tank[2].has && selah.has &&
                    (tank[2].x - selah.x) * (tank[2].x - selah.x) + (tank[2].y - selah.y) * (tank[2].y - selah.y) <
                    400) {
                    tank[2].laizer = 1;
                    //  tank[2].tir[5].por=true;
                    selah.has = 0;
                }
                if (tank[1].has && lazer.has &&
                    (tank[1].x - lazer.x) * (tank[1].x - lazer.x) + (tank[1].y - lazer.y) * (tank[1].y - lazer.y) <
                    400) {
                    tank[1].lazerasli = 1;
                    // tank[1].tir[5].por=true;
                    lazer.has = 0;
                }
                if (tank[2].has && lazer.has &&
                    (tank[2].x - lazer.x) * (tank[2].x - lazer.x) + (tank[2].y - lazer.y) * (tank[2].y - lazer.y) <
                    400) {
                    tank[2].lazerasli = 1;
                    //  tank[2].tir[5].por=true;
                    lazer.has = 0;
                }
                //thickLineRGBA(renderer,(750-toolran)/2,0,(750+toolran)/2,0,5,200,00,0,255);
                if (lazerbezan1 == 1) {
//                    if(hava==0){
//                        zav11=tank[1].zav;
//                        x11=tank[1].x;y11=tank[1].y;
//                    }
//                    if(sin(zav11)==1){
//                        thickLineRGBA(renderer,x11,y11,x11,0,5,40,40,40,255);
//                    }
//                    if(sin(zav11)==-1){
//                        thickLineRGBA(renderer,x11,y11,x11,arzran,5,40,40,40,255);
//                    }
//                    if(cos(zav11)==1){
//                        thickLineRGBA(renderer,x11,y11,(750+toolran)/2,y11,5,40,40,40,255);
//                    }
//                    if(cos(zav11)==-1){
//                        thickLineRGBA(renderer,x11,y11,(750-toolran)/2,y11,5,40,40,40,255);
//                    }int xx;
//                    if(sin(zav11)>0){
//                        xx=(-1*y11)/tan(zav11)+x11;
//                        if(xx>=(750-toolran)/2&&xx<=(750+toolran)/2){
//                            thickLineRGBA(renderer,x11,y11,xx,0,5,40,40,40,255);
//                            //return;
//                        }
//                    }
//                    if(sin(zav11)<0){
//                        xx=(arzran-y11)/tan(zav11)+x11;
//                        if(xx>=(750-toolran)/2&&xx<=(750+toolran)/2){
//                            thickLineRGBA(renderer,x11,y11,xx,arzran,5,40,40,40,255);
//                            // return;
//                        }
//                    }
//                    int yy;
//                    if(cos(zav11)<0){
//                        yy=tan(zav11)*(x11-(750-toolran)/2)+y11;
//                        if(yy>=0&&yy<=arzran){
//                            thickLineRGBA(renderer,x11,y11,(750-toolran)/2,yy,5,40,40,40,255);
//                            // return;
//                        }
//                    }
//                    if(cos(zav11)>0){
//                        yy=tan(zav11)*(x11-(750+toolran)/2)+y11;
//                        if(yy>=0&&yy<=arzran){
//                            thickLineRGBA(renderer,x11,y11,(750+toolran)/2,yy,5,40,40,40,255);
//                            // return;
//                        }
//                    }
                    bekash(renderer, 1.5 * snake_radius * cos(tank[1].zav) + tank[1].x,
                           tank[1].y - 1.5 * snake_radius * sin(tank[1].zav), tank[1].zav, arzran, toolran, tank,
                           snake_radius);
                    hava++;

                }
                // thickLineRGBA(renderer,100,0,600,0,70,255,255,255,255);
                if (hava == 20) {
                    lazerbezan1 = 0;
                    hava = 0;
                    tank[1].lazerasli = 0;
                }

                rasmtir(snake_radius, tank, renderer, step, map);
                if (tank[1].has == true) {
                    filledCircleRGBA(renderer, tank[1].x, tank[1].y, snake_radius, 0, 100, 100, 255);
                    thickLineRGBA(renderer, tank[1].x, tank[1].y, 1.5 * snake_radius * cos(tank[1].zav) + tank[1].x,
                                  tank[1].y - 1.5 * snake_radius * sin(tank[1].zav), 5, 0, 100, 100, 255);
                }
                if (tank[2].has == true) {
                    filledCircleRGBA(renderer, tank[2].x, tank[2].y, snake_radius, 100, 0, 100, 255);
                    thickLineRGBA(renderer, tank[2].x, tank[2].y, 1.5 * snake_radius * cos(tank[2].zav) + tank[2].x,
                                  tank[2].y - 1.5 * snake_radius * sin(tank[2].zav), 5, 100, 0, 100, 255);
                }
                if (tank[1].has == false || tank[2].has == false) {
                    if (tank[1].has == false) {
                        if (biroon == 30)tank2score++;
                        biroon--;
                    }
                    if (biroon == 30)tank1score++;
                    biroon--;
                }
                if (biroon == 0)break;
                // SDL_Surface *image=SDL_LoadBMP("C:\\Users\\majid\\Desktop\\IMG_20180121_0022.jpg");
                //SDL_Texture * texture=SDL_CreateTextureFromSurface(renderer,image);

                char *buffer = malloc(sizeof(char) * 50);
                char *biffer = malloc(sizeof(char) * 50);
                sprintf(buffer, "blue: %d "/* elapsed time: %dms"*/, tank1score/*, start_ticks - begining_of_time*/);
                sprintf(biffer, "violet: %d " /*elapsed time: %dms*/, tank2score/*, start_ticks - begining_of_time*/);

                //printf("%s", buffer);
                stringRGBA(renderer, 200, 450, buffer, 0, 100, 100, 255);
                stringRGBA(renderer, 500, 450, biffer, 100, 0, 100, 255);
                //SDL_RenderCopy(renderer,texture,NULL,NULL);



            }
            while (SDL_GetTicks() - start_ticks < 1000 / FPS);
            SDL_RenderPresent(renderer);
        }
        if (!flagasli || tank1score == nomre || tank2score == nomre) break;
        biroon = 30;
    }
    //SDL_Renderer *renderers = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (tank1score == nomre || tank2score == nomre) {
        //int e=0;
        while (1) {
            if (handleEvents() == 1) {
                flagasli = 0;
                break;
            }
            //int start_ticks = SDL_GetTicks();

            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            SDL_RenderClear(renderer);
            char *buffer = malloc(sizeof(char) * 50);
            char *biffer = malloc(sizeof(char) * 50);
            sprintf(buffer, "blue: %d "/* elapsed time: %dms"*/, tank1score/*, start_ticks - begining_of_time*/);
            sprintf(biffer, "violet: %d " /*elapsed time: %dms*/, tank2score/*, start_ticks - begining_of_time*/);
            stringRGBA(renderer, 200, 150, buffer, 0, 100, 100, 255);
            stringRGBA(renderer, 500, 150, biffer, 100, 0, 100, 255);
            if (tank1score == nomre) {
                stringRGBA(renderer, 300, 350, "THE WINNER IS BLUE", 0, 0, 0, 255);
            }
            if (tank2score == nomre) {
                stringRGBA(renderer, 300, 350, "THE WINNER IS vilolet", 0, 0, 0, 255);
            }
            SDL_RenderPresent(renderer);
            //e++;
        }
    }

    //SDL_DestroyRenderer(renderers);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    // if (handleEvents() == 1) break;
    //SDL_Delay(150);
    // }
//    SDL_DestroyRenderer(renderer);
//    SDL_DestroyWindow(window);
//
}