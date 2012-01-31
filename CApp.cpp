#include <iostream>
#include "CApp.h"

CApp::CApp() {
    Surf_Display = NULL;
    Surf_Test = NULL;
    Running = true;
}

int CApp::OnExecute() {
    if (CApp::OnInit() == false) {
        std::cerr << "OnInit() exited with an error" << std::endl;
        return -1;
    }

    SDL_Event Event;

    while(Running) { 
        while (SDL_PollEvent(&Event)) {
            CApp::OnEvent(&Event);
        }
    
        CApp::OnLoop();
        CApp::OnRender();
    
        }
    
    CApp::OnCleanup();
    
    return 0;
}

