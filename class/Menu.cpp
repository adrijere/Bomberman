//
// Created by marsil_g on 19/05/15.
//

#include        "../header/GameEngine.hpp"
#include        "../sdz_sdlglutils/sdlglutils.h"

bool	GameEngine::Menu(){
    if (!_context.start(1280, 720, "Main Menu")) // on cree une fenetre
        return false;

    return true;
}
