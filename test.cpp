#include "SDL.h"

int main(int argc, char* argv[]) {
    bool Running = true;
    SDL_Surface* Surf_Display = NULL;

    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
        return -1;

    if ((Surf_Display = SDL_SetVideoMode(1024, 768, 32, SDL_HWSURFACE || SDL_DOUBLEBUF)) == NULL)
        return -1;

    SDL_Event Event;

    while(Running) {
        while(SDL_PollEvent(&Event)) {
            if (Event.type == SDL_QUIT)
                Running = false;
        }
    }
    SDL_FreeSurface(Surf_Display);
    SDL_Quit();
    return 0;
}
