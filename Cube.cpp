#include "Cube.h"

ley::Cube::Cube() 
:rect{300,300,200,200}
{

}

SDL_Vertex ley::Cube::A(char atOrigin) {

    if(atOrigin == 1) {
        return {0, 0, red};
    }
    else if (atOrigin == 2) {
        return {-rect.w/2, -rect.h/2, red};
    }
    else {
        return {rect.x, rect.y, red};
    }
}

SDL_Vertex ley::Cube::B(char atOrigin) {

    if(atOrigin == 1) {
        return {rect.w, 0};
    }
    else if(atOrigin == 2) {
        return {rect.w/2, -rect.h/2, blue};
    }
    else {
        return {rect.x + rect.w, rect.y, blue};
    }
}

SDL_Vertex ley::Cube::C(char atOrigin) {
    
    if(atOrigin == 1) {
        return {rect.w, rect.h, green};
    }
    else if(atOrigin == 2) {
        return {rect.w/2, rect.h/2, green};
    }
    else {
        return {rect.x + rect.w, rect.y + rect.h, green};
    }
}

SDL_Vertex ley::Cube::D(char atOrigin) {

    if(atOrigin == 1) {
        return {0, rect.h, orange};
    }
    else if (atOrigin == 2) {
        return {-rect.w/2, rect.h/2};
    }
    else {
        return {rect.x, rect.y + rect.h, orange};
    }
}

float ley::Cube::x() {
    return rect.x;
}

float ley::Cube::y() {
    return rect.y;
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