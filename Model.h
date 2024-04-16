#pragma once

#include "Cube.h"
#include "Timer.h"

namespace ley {

class Model {

private:
    float mDegrees = 10;
    float mXDegrees = 0;
    float mYDegrees = 0;
    float mZDegrees = 0;
    Cube mCube1;
    Timer mTimer;

    float mXoffset = 0;
    float mYoffset = 0;

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

    void XDegreeUp();
    void XDegreeDown();
    void YDegreeUp();
    void YDegreeDown();
    void ZDegreeUp();
    void ZDegreeDown();
    float XDegrees();
    float YDegrees();
    float ZDegrees();
    void zeroDegress();
    

    ley::Timer* timer();

    SDL_FPoint offset();

};

}