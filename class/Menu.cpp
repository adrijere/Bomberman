//
// Created by marsil_g on 19/05/15.
//

#include        "../header/GameEngine.hpp"
#include        <SDL/SDL.h>

bool	GameEngine::Menu(){
    if (!_context.start(1920, 1080, "Main Menu")) // on cree une fenetre
        return false;

    /*    SDL_Surface *image = IMG_Load("../img/panda.bmp");
    if ( !image )
    {
        printf ( "IMG_Load: %s\n", IMG_GetError () );
        return 1;
    }

    // Draws the image on the screen:
    SDL_Rect rcDest = { 0, 0, 0, 0 };
    SDL_BlitSurface ( image, NULL, NULL, &rcDest );*/

    return true;
}
