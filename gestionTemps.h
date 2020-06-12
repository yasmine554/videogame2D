#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <math.h>
#include <time.h> 
/**
* @struct temps
* @brief structure temps
*/
struct temps
{
    int tempsActuel;
    int tempsPrecedent;
    int compteur;
    SDL_Surface *texte;
    SDL_Rect positionTemps;
    TTF_Font *police;
};
typedef struct temps temps;

void inittemps(temps *t);
void updatetemps(temps *t);
void affichage_temps(temps *t,char temps[]);
void blitTemps(temps *t,SDL_Surface *ecran);

