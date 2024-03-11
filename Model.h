#pragma once

#include "Cube.h"
#include "Timer.h"

namespace ley {

class Model {

private:
    float mDegrees = 10;
    Cube mCube1;
    Timer mTimer;

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

};

}