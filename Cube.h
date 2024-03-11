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

    SDL_Vertex A(char atOrigin = 0);
    SDL_Vertex B(char atOrigin = 0);
    SDL_Vertex C(char atOrigin = 0);
    SDL_Vertex D(char atOrigin = 0);

    float width();
    float height();

    float x();
    float y();

    void left();
    void right();
    void up();
    void down();
};
}