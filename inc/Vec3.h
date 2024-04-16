/* 
proto3dcube
Copyright (C) 2024 Steven Philley

Purpose: Vector.
Date: Apr/4/2024
*/

#ifndef VEC3_H
#define VEC3_H

namespace ley {

template<typename T>
class Vec3 {

public:
    Vec3() : x(T(0)), y(T(0)), z(T(0)) {}
    Vec3(const T &inValue) : x(inValue), y(inValue), z(inValue) {}
    Vec3(T inX, T inY, T inZ) : x(inX), y(inY), z(inZ) {}
    T x,y,z;

};


}

#endif