//
// Created by majid on 1/20/2019.
//

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
#include <math.h>
#include "rasma.h"
#include <time.h>
#include <SDL_test_images.h>
#include <SDL2_imageFilter.h>
#include "saveha.h"
void savekon(ssave save[],Map map,tanks tank[],int nomreh1,int nomreh2){
    int n=0;
    save[n].tankha[1]=tank[1];save[n].tankha[2]=tank[2];
    save[n].tankha[1].zav=tank[1].zav;save[n].tankha[2].zav=tank[2].zav;
    save[n].nomre1=nomreh1;
    save[n].nomre2=nomreh2;
     save[n].mapkomaki.tedad=map.tedad;
    for(int i=0;i<map.tedad;i++){
        save[n].mapkomaki.divar[i].x1=map.divar[i].x1;
        save[n].mapkomaki.divar[i].x2=map.divar[i].x2;
        save[n].mapkomaki.divar[i].y1=map.divar[i].y1;
        save[n].mapkomaki.divar[i].y2=map.divar[i].y2;
    }
}
void jabejayi(ssave save[],Map *map,tanks tank[],int *n1,int *n2){
    int n=0;
    map->tedad=save[n].mapkomaki.tedad;
    tank[1].x=save[n].tankha[1].x;
    tank[2].x=save[n].tankha[2].x;
    tank[1].y=save[n].tankha[1].y;
    tank[2].y=save[n].tankha[2].y;
    *n1=save[n].nomre1;*n2=save[n].nomre2;
    for(int i=0;i<map->tedad;i++){
        map->divar[i].x1=save[n].mapkomaki.divar[i].x1;
        map->divar[i].x2=save[n].mapkomaki.divar[i].x2;
        map->divar[i].y1=save[n].mapkomaki.divar[i].y1;
        map->divar[i].y2=save[n].mapkomaki.divar[i].y2;
    }
}
void klidmenu(int *flagup,int *flagdan,int *n,int a){
    if(a==2) {
        const Uint8 *currentKeyStates = SDL_GetKeyboardState(NULL);
        if (currentKeyStates[SDL_SCANCODE_UP] && *flagup == 1) {
            (*n)--;
            if (*n < 1)*n = 1;
            *flagup = 0;
        }
        if (currentKeyStates[SDL_SCANCODE_UP] == 0) {
            *flagup = 1;
        }
        if (currentKeyStates[SDL_SCANCODE_DOWN] && *flagdan == 1) {
            (*n)++;
            if (*n > 4)*n = 4;
            *flagdan = 0;
        }
        if (currentKeyStates[SDL_SCANCODE_DOWN] == 0) {
            *flagdan = 1;
        }
    }
    if(a==1){
        const Uint8 *currentKeyStates = SDL_GetKeyboardState(NULL);
        if (currentKeyStates[SDL_SCANCODE_UP] && *flagup == 1) {
            (*n)--;
            if (*n < 2)*n = 2;
            *flagup = 0;
        }
        if (currentKeyStates[SDL_SCANCODE_UP] == 0) {
            *flagup = 1;
        }
        if (currentKeyStates[SDL_SCANCODE_DOWN] && *flagdan == 1) {
            (*n)++;
            if (*n > 4)*n = 4;
            *flagdan = 0;
        }
        if (currentKeyStates[SDL_SCANCODE_DOWN] == 0) {
            *flagdan = 1;
        }
    }

}
void savina(int *flagasli,int *n,int *t,ssave saveha[],Map *map,tanks tank[],int *tank1score,int *tank2score,selahs *selah){
    const Uint8* currentKeyStates = SDL_GetKeyboardState( NULL );
    if(currentKeyStates[ SDL_SCANCODE_RETURN]){
        if(*n==1){
            //savekon(saveha, *map, tank, *tank1score, *tank2score);
            saveakhar(*map,tank,*tank1score,*tank2score,*selah);
            (*t)++;
        }
        if(*n==2){
            (*t)++;
        }
        if(*n==3){
            (*t)++;
            //jabejayi(saveha,map,tank,tank1score,tank2score);
            bekhoonesh(map,tank,tank1score,tank2score,selah);
        }
        if(*n==4){
            *flagasli=0;
        }
    }
}
void lazereshoon(SDL_Renderer *renderer,double x,double y,int tool,int arz,double zav){
    double megh=3.14/90;
    for(int i=(750-tool)/2;i<=(750+tool)/2;i++){
        if(sin(zav-megh)<=sin(y/(x-i))&&sin(y/(x-i))<=sin(zav+megh)){
            thickLineRGBA(renderer,x,y,i,0,3,0,100,0,255);
            return;
        }
    }
    for(int i=0;i<=arz;i++){
        if(sin(zav-megh)<=sin((y-i)/(x-(750-tool)/2))&&sin((y-i)/(x-(750-tool)/2))<=sin(zav+megh)){
            thickLineRGBA(renderer,x,y,(750-tool)/2,i,3,0,100,0,255);
            return;
        }
    }
    for(int i=(750-tool)/2;i<=(750+tool)/2;i++){
        if(sin(zav-megh)<=sin((y-arz)/(x-i))&&sin((y-arz)/(x-i))<=sin(zav+megh)){
            thickLineRGBA(renderer,x,y,arz,0,3,0,100,0,255);
            return;
        }
    }
    for(int i=0;i<=arz;i++){
        if(sin(zav-megh)<=sin((y-i)/(x-(750+tool)/2))&&sin((y-i)/(x-(750+tool)/2))<=sin(zav+megh)){
            thickLineRGBA(renderer,x,y,(750+tool)/2,i,3,0,100,0,255);
            return;
        }
    }
}
void bekash(SDL_Renderer *renderer,double x,double y,double zav,int arz,int tool,tanks tank[],int r){
//     if(sin(zav)==1){
//         thickLineRGBA(renderer,x,y,x,0,5,40,40,40,255);
//         return;
//     }
//    if(sin(zav)==-1){
//        thickLineRGBA(renderer,x,y,x,arz,5,40,40,40,255);
//        return;
//    }
//    if(cos(zav)==1){
//        thickLineRGBA(renderer,x,y,(750+tool)/2,y,5,40,40,40,255);
//        return;
//    }
//    if(cos(zav)==-1){
//        thickLineRGBA(renderer,x,y,(750-tool)/2,y,5,40,40,40,255);
//        return;
//    }int xx;
//    if(sin(zav)>0){
//        xx=(-1*y)/tan(zav)+x;
//        if(xx>=(750-tool)/2&&xx<=(750+tool)/2){
//            thickLineRGBA(renderer,x,y,xx,0,5,40,40,40,255);
//        }
//    }
//    if(sin(zav)<0){
//        xx=(arz-y)/tan(zav)+x;
//        if(xx>=(750-tool)/2&&xx<=(750+tool)/2){
//            thickLineRGBA(renderer,x,y,xx,arz,5,40,40,40,255);
//        }
//    }
//    int yy;
//    if(cos(zav)<0){
//        yy=tan(zav)*(x-(750-tool)/2)+y;
//        if(yy>=0&&yy<=arz){
//            thickLineRGBA(renderer,x,y,(750-tool)/2,yy,5,40,40,40,255);
//        }
//    }
//    if(cos(zav)>0){
//        yy=tan(zav)*(x-(750+tool)/2)+y;
//        if(yy>=0&&yy<=arz){
//            thickLineRGBA(renderer,x,y,(750+tool)/2,yy,5,40,40,40,255);
//        }
//    }

thickLineRGBA(renderer,x,y,600 * cos(zav) + x,y - 600* sin(zav),5,100,0,0,255);
int m=sin(zav)/cos(zav);
if(sin(zav)>0) {
    int y1,y2,x11,y3;
    y1=y+1.5*r*sin(zav);y2=y;
    y3=tank[2].y-r;
    if(y3<y1) {
        if (fabs((m * tank[2].x - m * x + y - tank[2].y) / (m * m + 1)) < r)tank[2].has = false;
    }
}
if(sin(zav)<0){
    int y1,y2,x11,y3;
    y1=y+1.5*r*sin(zav);y2=y;
    y3=tank[2].y+r;
    if(y3>y1) {
        if (fabs((m * tank[2].x - m * x + y - tank[2].y) / (m * m + 1)) < r)tank[2].has = false;
    }
}
}



int saveakhar(Map map,tanks tank[],int s1,int s2,selahs selah){
    FILE *f=fopen("C:\\Users\\majid\\Desktop\\project\\src\\vv.txt","w");
    //if(tank[1].laizer==true)
    fprintf(f,"%lf %lf %d %d\n",tank[1].x,tank[1].y,s1,tank[1].laizer);
    fprintf(f,"%lf %lf %d %d\n",tank[2].x,tank[2].y,s2,tank[2].laizer);
    fprintf(f,"%d\n",map.tedad);
    for(int i=0;i<map.tedad;i++){
        fprintf(f,"%lf %lf %lf %lf\n",map.divar[i].x1,map.divar[i].y1,map.divar[i].x2,map.divar[i].y2);
    }
    fprintf(f,"%d %lf %lf %d\n",selah.has,selah.x,selah.y,selah.zaman);

    fclose(f);
}
void bekhoonesh(Map *map,tanks tank[],int *s1,int *s2,selahs *selah){
    FILE *f=fopen("C:\\Users\\majid\\Desktop\\project\\src\\vv.txt","r");
    double c,cc;int ccc,cccc;
    fscanf(f,"%lf %lf %d %d\n",&c,&cc,&ccc,&cccc);
    tank[1].x=c; tank[1].y=cc; *s1=ccc;tank[1].laizer=cccc;
    double s,ss;int sss,ssss;
    fscanf(f,"%lf %lf %d %d\n",&s,&ss,&sss,&ssss);
    tank[2].x=s; tank[2].y=ss; *s2=sss;tank[2].laizer=ssss;
    int n;
    fscanf(f,"%d\n",&n);
    map->tedad=n;
    for(int i=0;i<map->tedad;i++){
        double a1,a2,b1,b2;
        fscanf(f,"%lf %lf %lf %lf\n",&a1,&a2,&b1,&b2);
        map->divar[i].x1=a1;
        map->divar[i].y1=a2;
        map->divar[i].x2=b1;
        map->divar[i].y2=b2;
    }
    int h;double v,y ;int z;
    fscanf(f,"%d %lf %lf %d\n",&h,&v,&y,&z);
    selah->has=h;selah->x=v;selah->y=y;selah->zaman=z;
fclose(f);
}