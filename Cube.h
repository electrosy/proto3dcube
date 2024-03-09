#pragma once

#include <SDL2/SDL.h>

const SDL_Color red{255,0,0,255};
const SDL_Color blue{0,255,0,255};
const SDL_Color green{0,0,255,255};
const SDL_Color orange{255,165,0,255};

namespace ley {

class Cube
{

private:

    SDL_FRect rect;

public:

    Cube();

    SDL_Vertex A();
    SDL_Vertex B();
    SDL_Vertex C();
    SDL_Vertex D();

    float width();
    float height();

    void left();
    void right();
    void up();
    void down();
};
}