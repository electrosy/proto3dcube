/* 
proto3dcube
Copyright (C) 2024 Steven Philley

Purpose: Matrix 4x4.
Date: Apr/15/2024
*/

#ifndef MATRIX44_H
#define MATRIX44_H

#include <stdint.h>
#include "./Vec3.h"

namespace ley {

template<typename T>
class Matrix44 {

public:
    Matrix44() {}
    const T* operator [] (uint8_t i) const {return m[i];}
    T* operator [] (uint8_t i) {return m[i];}
    T m[4][4] = {{1,0,0,0},{0,1,0,0},{0,0,1,0},{0,0,0,1}};

    Vec3<T> multVecMatrix(const Vec3<T> &v) {
    //row major
    return Vec3<T>(
        v.x * m[0][0] + v.y * m[1][0] + v.z * m[2][0],
        v.x * m[0][1] + v.y * m[1][1] + v.z * m[2][1],
        v.x * m[0][2] + v.y * m[1][2] + v.z * m[2][2]);};

    Matrix44<T> operator*(const Matrix44<T>& rhs) const {
    Matrix44<T> mult;

    for(auto i = 0; i < 4; ++i) {
        for(auto j = 0; j < 4; ++j) {
            mult[i][j] = m[i][0] * rhs[0][j] +
                            m[i][1] * rhs[1][j] +
                            m[i][2] * rhs[2][j] +
                            m[i][3] * rhs[3][j];
        }
    }

    return mult;};
};

}

#endif