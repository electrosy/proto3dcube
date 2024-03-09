/* 
proto3dcube
Copyright (C) 2024 Steven Philley

Purpose: Input System for the project.
Date: Jan/2/2024
*/

#ifndef INPUT_H
#define INPUT_H

#include <SDL2/SDL.h>

namespace ley {

enum class Command {
    pgup,
    pgdown,
    up,
    down,
    left,
    right,
    enter,
    quit,
    none
    };

class Input {

private:
  
public:
    Input();
    ~Input();
    ley::Command pollEvents();
    
};

}
#endif
