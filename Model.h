#pragma once

#include "Cube.h"

namespace ley {

class Model {

private:
    float mDegrees = 30;
    Cube mCube1;

public:
    void setDegrees(float d);
    float getDegrees();
    void degreeUp();
    void degreeDown();
    Cube cube();

    void left();
    void right();
    void up();
    void down();

};

}