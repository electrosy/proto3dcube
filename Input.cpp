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

                break;

            default:
                break;
        }
     }

     return command;
}