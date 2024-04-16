#include "Transform.h"


#define PI 3.14159265

SDL_FPoint ley::Transform::rotate(SDL_FPoint p, float a) {
    

    //convert degress to radians
    a = toRad(a);

    float x = p.x * cos(a) - p.y * sin(a);
    float y = p.x * sin(a) + p.y * cos(a);
    
    //SDL_Log("x:%f", x);
    //SDL_Log("y:%f", y);

    return {x,y};
}

float ley::Transform::toRad(float deg) {
    return deg * PI / 180.0;
}

