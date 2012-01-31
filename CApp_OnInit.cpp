#include <iostream>
#include "CApp.h"

bool CApp::OnInit() {
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
        return false;
    
    if ((Surf_Display = SDL_SetVideoMode(800, 600, 32, SDL_HWSURFACE | SDL_DOUBLEBUF)) == NULL)
            return false;
    
    if ((Surf_Test = CSurface::OnLoad("bg.bmp")) == NULL) {
        std::cerr << "OnLoad() encountered an error" << std::endl;
        return false;
    }

    return true;
}
