#ifndef BMATH_VECTOR
#define BMATH_VECTOR

#include <math.h>

namespace bMath {
    struct Vector3 {
        float x,y,z;

        Vector3() : x(0), y(0), z(0) {}

        Vector3(float x,float y,float z) : x(x), y(y), z(z) {}

        Vector3 operator+(const Vector3 &v) const {
            return Vector3(x+v.x,y+v.y,z+v.z);
        }
        void operator+=(const Vector3 &v) {
            x += v.x;
            y += v.y;
            z += v.z;
        }

        Vector3 operator*(const float s) const {
            return Vector3(x*s,y*s,z*s);
        }
        void operator*=(const float s) {
            x *= s;
            y *= s;
            z *= s;
        }

        Vector3 operator-(const Vector3 &v) const {
            return Vector3(x-v.x,y-v.y,z-v.z);
        }
        void operator-=(const Vector3 &v) {
            x -= v.x;
            y -= v.y;
            z -= v.z;
        }

        Vector3 cross(const Vector3 &v) const {
            return Vector3(
                y*v.z-z*v.y,
                z*v.x-x*v.z,
                x*v.y-y*v.x
            );
        }
        
        float dot(const Vector3 &v) const {
            return x*v.x+y*v.y+z*v.z;
        }

        float magnitude() const {
            return sqrt(x*x+y*y+z*z);
        }
        float squareMagnitude() const {
            return (x*x+y*y+z*z);
        }

        void normalize() {
            float length = magnitude();
            if (length > 0) {
                (*this) *= ((float)1/length);
            }
        }
    };

    float dot(Vector3 a, Vector3 b) {
        return  a.x*b.x+a.y*b.y+a.z*b.z;
    }

    Vector3 cross(Vector3 a, Vector3 b) {
        return Vector3(
                a.y*b.z-a.z*b.y,
                a.z*b.x-a.x*b.z,
                a.x*b.y-a.y*b.x
        );
    }

    // TODO
    Vector3 lerp(Vector3 a, Vector3 b) {
        return Vector3();
    }

    //TODO
    Vector3 min(Vector3 a, Vector3 b) {
        return Vector3();
    }
    
    //TODO
    Vector3 max(Vector3 a, Vector3 b) {
        return Vector3();
    }

    //TODO
    Vector3 clamp(Vector3 a, Vector3 b) {
        return Vector3();
    }
}

#endif