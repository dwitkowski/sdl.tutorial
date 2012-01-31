#include "CEvent.h"

CEvent::CEvent(); {
}

CEvent::~CEvent() {
}

void CEvent::OnEvent(SDL_Event* Event) {
    switch(Event->type) {
        case SDL_ACTIVEEVENT: {
            switch(Event->active.state) {
                case SDL_APPMOUSEFOCUS: {
                    if ( Event->active.gain )
                        OnMouseFocus();
                    else
                        OnMouseBlur();
                    break;
                }
                case SDL_APPINPUTFOCUS: {
                    if ( Event->active.gain )
                        OnInputFocus();
                    else
                        OnInputBlur();
                    break;
                }
                case SDL_APPACTIVE: {
                    if ( Event->active.gain )
                        OnRestore();
                    else
                        OnMinimize();
                    break;
                }
            }
            break;
        }
       // STILL TODO 
    

            
