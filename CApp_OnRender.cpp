#include "CApp.h"

void CApp::OnRender() {
    CSurface::OnDraw(Surf_Display, Surf_Test, 0, 0);
    // Enable double buffering to avoid screen flicker.
    SDL_Flip(Surf_Display);
}
