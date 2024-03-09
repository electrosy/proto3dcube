#include "Model.h"

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
}

void ley::Model::right() {
    mCube1.right();
}

void ley::Model::up() {
    mCube1.up();
}

void ley::Model::down() {
    mCube1.down();
}

