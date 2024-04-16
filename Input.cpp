/* 
proto3dcube
Copyright (C) 2024 Steven Philley

Purpose: see header.
Date: Jan/2/2024
*/
#include "Input.h"
#include "Video.h"

/* RAII */
ley::Input::Input() {
    
}

ley::Input::~Input() {

}

/* Functions */

ley::Command ley::Input::pollEvents() {
    SDL_Event event;
    ley::Command command = ley::Command::none; //direction for this frame;

    while(SDL_PollEvent(&event))   {    //SDL_PollEvent calls pumpevents.
        const Uint8 *state = SDL_GetKeyboardState(NULL);
        switch (event.type)     {       
            case SDL_QUIT:         
                command = ley::Command::quit;
                break;
            
            case SDL_KEYDOWN:
                if(state[SDL_SCANCODE_RETURN]) {
                    command = ley::Command::enter;
                }               

                if(state[SDL_SCANCODE_ESCAPE]) {
                    command = ley::Command::quit;
                }

                if(state[SDL_SCANCODE_UP]) {
                    command = ley::Command::up;
                }

                if(state[SDL_SCANCODE_DOWN]) {
                    command = ley::Command::down;
                }

                if(state[SDL_SCANCODE_LEFT]) {
                    command = ley::Command::left;
                }

                if(state[SDL_SCANCODE_RIGHT]) {
                    command = ley::Command::right;
                }

                if(state[SDL_SCANCODE_PAGEUP]) {
                    command = ley::Command::pgup;
                }

                if(state[SDL_SCANCODE_PAGEDOWN]) {
                    command = ley::Command::pgdown;
                }

                if(state[SDL_SCANCODE_INSERT]) {
                    command = ley::Command::ins;
                }

                if(state[SDL_SCANCODE_DELETE]) {
                    command = ley::Command::del;
                }

                if(state[SDL_SCANCODE_HOME]) {
                    command = ley::Command::home;
                }

                if(state[SDL_SCANCODE_END]) {
                    command = ley::Command::end;
                }

                if(state[SDL_SCANCODE_SPACE]) {
                    command = ley::Command::space;
                }

                break;

            default:
                break;
        }
     }

     return command;
}