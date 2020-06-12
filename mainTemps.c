/**
* @file mainTemps.c
* @brief  fichier main du gestion de temps
* @author NOT YET Yasmine sliti 1A3
* @version 1.0
* @date June 2020

*/
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include "gestionTemps.c"

int main(int argc,char *argv[])
{
    SDL_Surface *ecran=NULL,*texte=NULL;
    SDL_Rect position;
    SDL_Event event;
    SDL_Color couleurNoire= {0,0,0},couleurBlanche= {255,255,255};
    int continuer=1;
    temps t;
    char temps[200]="";//Tableau de char suffisamment grand
    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();
    ecran=SDL_SetVideoMode(640,480,32,SDL_HWSURFACE | SDL_DOUBLEBUF);
    //Initialisation de la structure temps
    inittemps(&t);
    //Initialisation de la variable tempsActuel
    t.tempsActuel=SDL_GetTicks();

    while(continuer)
    {
        SDL_PollEvent(&event);
        switch(event.type)
        {
        case SDL_QUIT:
            continuer=0;
            break;
        }
        SDL_FillRect(ecran,NULL,SDL_MapRGB(ecran->format,255,255,255));
        updatetemps(&t);
        affichage_temps(&t,temps);

        blitTemps(&t,ecran);
        printf("%d",5);
        SDL_Flip(ecran);
        SDL_Delay(1000);
    }
    TTF_CloseFont(t.police);
    TTF_Quit();

    SDL_FreeSurface(t.texte);
    SDL_Quit();

    return EXIT_SUCCESS;
}
