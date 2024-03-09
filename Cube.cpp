#include "Cube.h"

ley::Cube::Cube() 
:rect{300,300,200,200}
{

}

SDL_Vertex ley::Cube::A() {
    return {rect.x, rect.y, red};
}

SDL_Vertex ley::Cube::B() {
    return {rect.x + rect.w, rect.y, blue};
}

SDL_Vertex ley::Cube::C() {
    return {rect.x + rect.w, rect.y + rect.h, green};
}

SDL_Vertex ley::Cube::D() {
    return {rect.x, rect.y + rect.h, orange};
}

float ley::Cube::width() {
    return rect.w;
}

float ley::Cube::height() {
    return rect.h;
}

void ley::Cube::left() {
    rect.x = rect.x -= 1;
}

void ley::Cube::right() {
    rect.x = rect.x += 1;
}

void ley::Cube::up() {
    rect.y = rect.y -= 1;
}

void ley::Cube::down() {
    rect.y = rect.y += 1;
}