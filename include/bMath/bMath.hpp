#ifndef BMATH_BMATH
#define BMATH_BMATH

#include "Vector.hpp"
#include "Matrix.hpp"
#include "Quaternion.hpp"
#include <math.h>

namespace bMath {
    // TODO
    Vector3 RotateVector(const Vector3 &v, const Quaternion &q) {
        float x = v.x*(q.x*q.x-q.y*q.y-q.z*q.z+q.w*q.w)+v.y*(2*q.x*q.y-2*q.w*q.z)+v.z*(2*q.x*q.z+2*q.w*q.y);
        return Vector3();
    }
}

#endif