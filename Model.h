#pragma once

#include "Cube.h"
#include "Timer.h"

namespace ley {

class Model {

private:
    float mDegrees = 10;
    Cube mCube1;
    Timer mTimer;

    float mXoffset = 100;
    float mYoffset = 100;

public:
    Model();
    void setDegrees(float d);
    float getDegrees();
    void degreeUp();
    void degreeDown();
    Cube cube();

    void left();
    void right();
    void up();
    void down();

    ley::Timer* timer();

    SDL_FPoint offset();

};

}