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
        case SDL_KEYDOWN: {
            OnKeyDown(Event->key.keysym.sym, Event->key.keysym.mod, Event->key.keysym.unicode);
            break;
        }

        case SDL_KEYUP: {
            OnKeyUp(Event->key.keysym.sym, Event->key.keysym.mod, Event->key.keysym.unicode);
            break;
        }
        case SDL_MOUSEMOTION: {
            OnMouseMove(Event->motion.x, Event->motion.y, Event->motion.xrel, Event->motion.yrel,
                    (Event->motion.state&SDL_BUTTON(SDL_BUTTON_LEFT)) != 0,
                    (Event->motion.state&SDL_BUTTON(SDL_BUTTON_RIGHT)) != 0,
                    (Event->motion.state&SDL_BUTTON(SDL_BUTTON_MIDDLE)) != 0);
            break;
        }
        case SDL_MOUSEBUTTONDOWN: {
            switch(Event->button.button) {
                case SDL_BUTTON_LEFT: {
                    OnLButtonDown(Event->button.x, Event->button.y);
                    break;
                }
                case SDL_BUTTON_RIGHT: {
                    OnRButtonDown(Event->button.x, Event->button.y);
                    break;
                }
                case SDL_BUTTON_MIDDLE: {
                    OnMButtonDown(Event->button.x, Event->button.y);
                    break;
                }
            }
            break;
        }
        case SDL_MOUSEBUTTONUP: {
            switch(Event->button.button) {
                case SDL_BUTTON_LEFT: {
                    OnLButtonUp(Event->button.x, Event->button.y);
                    break;
                }
                case SDL_BUTTON_RIGHT: {
                    OnRButtonUp(Event->button.x, Event->button.y);
                    break;
                }
                case SDL_BUTTON_MIDDLE: {
                    OnMButtonUp(Event->button.x, Event->button.y);
                    break;
                }
            }
            break;
        }

            
