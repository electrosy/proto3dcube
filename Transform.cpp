#include "Transform.h"


#define PI 3.14159265

ley::Transform::Transform() {

}

SDL_FPoint ley::Transform::rotate(SDL_FPoint p, float a) {
    

    //convert degress to radians
    a = a * PI / 180.0;

    float x = p.x * cos(a) - p.y * sin(a);
    float y = p.x * sin(a) + p.y * cos(a);
    
    SDL_Log("x:%f", x);
    SDL_Log("y:%f", y);

    return {x,y};
}