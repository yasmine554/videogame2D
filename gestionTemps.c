/**
* @file gestionTemps.c
* @brief  fichier.c de la gestion du temps.=
* @author NOT YET Yasmine Sliti 1A3
* @version 1.0
* @date June 2020

*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <math.h>
#include <time.h>
#include "gestionTemps.h"

/**@brief Initialisation de la structure temps
   @param b struct temps
   @return void
*/
void inittemps(temps *t)
{
    t->tempsActuel=0;
    t->tempsPrecedent=0;
    t->compteur=0;
    t->texte=NULL;
    t->positionTemps.x=10;
    t->positionTemps.y=250;
    t->police =TTF_OpenFont("yass.ttf",30) ;//Chargement de ma police
	
}

/**@brief incrementation de la variable entiere compteur
   @param b struct temps
   @return void
*/
void updatetemps(temps *t)
{
    t->tempsActuel=SDL_GetTicks();
    if((t->tempsActuel)- (t->tempsPrecedent)>=1000)// Si 1000 ms=1 s au moins se sont écoulées
    {
        t->compteur+=1;// On incrémente le compteur par 1
        t->tempsPrecedent=t->tempsActuel;//On met a jour le temps précedent
    }
}

/**@brief Affichage du temps
   @param t struct temps
   @return void
*/

void affichage_temps(temps *t,char temps[])
{
    int mm=0,ss=0;
    SDL_Color couleurNoire={0,0,0};
    mm=(t->compteur)/60;
    ss=(t->compteur)-mm*60;
    sprintf(temps,"%d:%d",mm,ss);// On écrit dans la chaîne "temps"
    SDL_FreeSurface(t->texte);//On supprime la surface précedente
    t->texte =TTF_RenderText_Solid(t->police,temps,couleurNoire);
}

/**@brief Blit du texte
   @param t struct temps
   @return void
*/
void blitTemps(temps *t,SDL_Surface *ecran)
{
    SDL_BlitSurface(t->texte,NULL,ecran,&(t->positionTemps));//blit du texte
}

