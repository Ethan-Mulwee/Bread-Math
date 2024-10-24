#ifndef BMATH_QUATERNION
#define BMATH_QUATERNION

#include <math.h>
#include "Vector.hpp"
#include "Matrix.hpp"

namespace bMath {
    struct Quaternion {
        float w,x,y,z;

        Quaternion() {}

        Quaternion(float w, float x, float y, float z)
        : w(w), x(x), y(y), z(z) {}

        Quaternion operator+(const Quaternion &q) const {
            return Quaternion(w+q.w,x+q.x,y+q.y,z+q.z);
        }

        Quaternion operator*(const Quaternion &q) const {
            return Quaternion();
        }

        void rotate(const Vector3 &v) {
            
        }

        Matrix<3,3> ToMatrix() {
            return Matrix<3,3>();
        }
    };

    Quaternion QuaternionFromAxisAngle(float angle, Vector3 axis) {
        float a = cos(angle);
        return Quaternion(sin(angle), a*axis.x, a*axis.y, a*axis.z);
    }
}

#endif