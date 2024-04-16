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

void ley::Model::XDegreeUp() {
    mXDegrees += 1;
}

void ley::Model::XDegreeDown() {
    mXDegrees -= 1;
}

void ley::Model::YDegreeUp() {
    mYDegrees += 1;
}

void ley::Model::YDegreeDown() {
    mYDegrees -= 1;
}

void ley::Model::ZDegreeUp() {
    mZDegrees += 1;
}

void ley::Model::ZDegreeDown() {
    mZDegrees -= 1;
}

float ley::Model::XDegrees() {
    return mXDegrees;
}

float ley::Model::YDegrees() {
    return mYDegrees;
}

float ley::Model::ZDegrees() {
    return mZDegrees;
}

void ley::Model::zeroDegress() {
    mZDegrees = mXDegrees = mYDegrees = 0;
}