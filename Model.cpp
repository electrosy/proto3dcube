#include "Model.h"

ley::Model::Model()
:
mTimer{50, {0,0,0,0}} {

}

void ley::Model::setDegrees(float d) {
    mDegrees = d;
}

float ley::Model::getDegrees() {
    return mDegrees;
}

void ley::Model::degreeUp() {
    mDegrees += 1;
}

void ley::Model::degreeDown() {
    mDegrees -= 1;
}

ley::Cube ley::Model::cube() {
    return mCube1;
}

void ley::Model::left() {
    mCube1.left();

    mXoffset -= 1;
}

void ley::Model::right() {
    mCube1.right();

    mXoffset += 1;
}

void ley::Model::up() {
    mCube1.up();

    mYoffset -= 1;
}

void ley::Model::down() {
    mCube1.down();

    mYoffset += 1;
}

ley::Timer* ley::Model::timer() {
    return &mTimer;
}

SDL_FPoint ley::Model::offset() {
    return {mXoffset, mYoffset};
}

