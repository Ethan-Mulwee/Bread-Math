#ifndef BMATH_VECTOR
#define BMATH_VECTOR

#include <math.h>
#include <iostream>
#include "Float.hpp"

namespace bMath {
    template <typename T, int n>
    struct Vector {
        T data[n];

        template <typename... Args>
        Vector(Args... args) : data{(T)args...} {}

        T& operator[](int i) {
            return data[i];
        }

        T operator[](int i) const {
            return data[i];
        }

        // Vector3 operator+(const Vector3 &v) const {
        //     return Vector3(x+v.x,y+v.y,z+v.z);
        // }
        // void operator+=(const Vector3 &v) {
        //     x += v.x;
        //     y += v.y;
        //     z += v.z;
        // }

        // Vector3 operator*(const float s) const {
        //     return Vector3(x*s,y*s,z*s);
        // }
        // void operator*=(const float s) {
        //     x *= s;
        //     y *= s;
        //     z *= s;
        // }

        // Vector3 operator-(const Vector3 &v) const {
        //     return Vector3(x-v.x,y-v.y,z-v.z);
        // }

        // void operator-=(const Vector3 &v) {
        //     x -= v.x;
        //     y -= v.y;
        //     z -= v.z;
        // }


        // Vector3 cross(const Vector3 &v) const {
        //     return Vector3(
        //         y*v.z-z*v.y,
        //         z*v.x-x*v.z,
        //         x*v.y-y*v.x
        //     );
        // }
        
        // float dot(const Vector3 &v) const {
        //     return x*v.x+y*v.y+z*v.z;
        // }

        // float magnitude() const {
        //     return sqrt(x*x+y*y+z*z);
        // }
        // float squareMagnitude() const {
        //     return (x*x+y*y+z*z);
        // }

        // void normalize() {
        //     float length = magnitude();
        //     if (length > 0) {
        //         (*this) *= ((float)1/length);
        //     }
        // }

    };

    template <> struct Vector<float, 2> { 
        union {float data[2]; struct { float x, y; };}; 
        
        template <typename... Args>
        Vector(Args... args) : data{(float)args...} {}

        float& operator[](int i) {
            return data[i];
        }

        float operator[](int i) const {
            return data[i];
        }
    };
    template <> struct Vector<float, 3> { 
        union { float data[3]; struct { float x, y, z; };    };

        template <typename... Args>
        Vector(Args... args) : data{(float)args...} {}

        float& operator[](int i) {
            return data[i];
        }

        float operator[](int i) const {
            return data[i];
        }
    };
    template <> struct Vector<float, 4> { 
        union { float data[4]; struct { float x, y, z, w; }; }; 
                
        template <typename... Args>
        Vector(Args... args) : data{(float)args...} {}

        float& operator[](int i) {
            return data[i];
        }

        float operator[](int i) const {
            return data[i];
        }
    };

    typedef Vector<float, 2> float2;
    typedef Vector<float, 3> float3;
    typedef Vector<float, 4> float4;

    typedef Vector<int, 2> int2;
    typedef Vector<int, 3> int3;
    typedef Vector<int, 4> int4;

    template<typename T, int n>
    std::ostream& operator<<(std::ostream& os, const Vector<T,n> &v) {
        os << "(";
        for (int i = 0; i < n; i++) {
            os << v[i] << ((i!=n-1) ? ", " : "");
        }
        os << ")";
        return os;
    }

    template<typename T, int n>
    Vector<T,n> operator+(const Vector<T,n> &a, const Vector<T,n> &b) {
        Vector<T,n> result;
        for (int i = 0; i < n; i++) {
            result[i] = a[i]+b[i];
        }
        return result;
    }
    
    template<typename T, int n>
    Vector<T,n> operator*(const Vector<T,n> &a, const float b) {
        Vector<T,n> result;
        for (int i = 0; i < n; i++) {
            result[i] = a[i]*b;
        }
        return result;
    }


    // float dot(Vector3 a, Vector3 b) {
    //     return  a.x*b.x+a.y*b.y+a.z*b.z;
    // }

    // Vector3 cross(Vector3 a, Vector3 b) {
    //     return Vector3(
    //             a.y*b.z-a.z*b.y,
    //             a.z*b.x-a.x*b.z,
    //             a.x*b.y-a.y*b.x
    //     );
    // }

    // Vector3 max(Vector3 a, Vector3 b) {
    //     float x = std::max(a.x,b.x);
    //     float y = std::max(a.y,b.y);
    //     float z = std::max(a.z,b.z);
    //     return Vector3(x,y,z);
    // }

    // Vector3 min(Vector3 a, Vector3 b) {
    //     float x = std::min(a.x,b.x);
    //     float y = std::min(a.y,b.y);
    //     float z = std::min(a.z,b.z);
    //     return Vector3(x,y,z);
    // }

    // Vector3 lerp(Vector3 a, Vector3 b, float t) {
    //     float x = lerp(a.x,b.x,t);
    //     float y = lerp(a.y,b.y,t);
    //     float z = lerp(a.z,b.z,t);
    //     return Vector3(x,y,z);
    // }

    // float distance(Vector3 a, Vector3 b) {
    //     return std::abs((a-b).magnitude());
    // }



    // //TODO
    // Vector3 clamp(Vector3 a, Vector3 b) {
    //     return Vector3();
    // }
}

#endif