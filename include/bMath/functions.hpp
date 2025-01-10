#ifndef BMATH_FUNCTIONS
#define BMATH_FUNCTIONS

#include "vector.hpp"
#include "quaternion.hpp"
#include "matrix.hpp"

namespace bMath {
  // TODO: Generalize vector transformation operations to any type not just floats

  // optimized 3x3 vector3 transformation
  inline float3 operator*(const float3 &v, const matrix3 &m) {
    return float3(
      v.x*m(0,0)+v.y*m(0,1)+v.z*m(0,2),
      v.x*m(1,0)+v.y*m(1,1)+v.z*m(1,2),
      v.x*m(2,0)+v.y*m(2,1)+v.z*m(2,2)
    );
  }

  // optimized 4x4 vector3 transformation
  inline float3 operator*(const float3 &v, const matrix4 &m) {
    return float3(
      v.x*m(0,0)+v.y*m(0,1)+v.z*m(0,2)+m(0,3),
      v.x*m(1,0)+v.y*m(1,1)+v.z*m(1,2)+m(1,3),
      v.x*m(2,0)+v.y*m(2,1)+v.z*m(2,2)+m(2,3)
    );
  }

  // optimized 4x4 vector4 transformation
  inline float4 operator*(const float4 &v, const matrix4 &m) {
    return float4(
      v.x*m(0,0)+v.y*m(0,1)+v.z*m(0,2)+v.w*m(0,3),
      v.x*m(1,0)+v.y*m(1,1)+v.z*m(1,2)+v.w*m(1,3),
      v.x*m(2,0)+v.y*m(2,1)+v.z*m(2,2)+v.w*m(2,3),
      v.x*m(3,0)+v.y*m(3,1)+v.z*m(3,2)+v.w*m(3,3)
    );
  }

    // Transform a vector by a quaternion
  template <typename T>
  Vector<T,3> rotate(const Vector<T,3> &v, const quaternion &q) {
    return Vector<T,3>(
      v.x*(q.x*q.x-q.y*q.y-q.z*q.z+q.w*q.w)+v.y*(2*q.x*q.y-2*q.w*q.z)+v.z*(2*q.x*q.z+2*q.w*q.y),
      v.x*(2*q.w*q.z+2*q.x*q.y)+v.y*(q.w*q.w-q.x*q.x+q.y*q.y-q.z*q.z)+v.z*(2*q.y*q.z-2*q.w*q.x),
      v.x*(2*q.x*q.z-2*q.w*q.y)+v.y*(2*q.w*q.x+2*q.y*q.z)+v.z*(q.w*q.w-q.x*q.x-q.y*q.y+q.z*q.z)
    );
  }


  // Transform a vector by a quaternion
  template <typename T>
  Vector<T,3> operator*(const Vector<T,3> &v, const quaternion &q) {
    return Vector<T,3>(
      v.x*(q.x*q.x-q.y*q.y-q.z*q.z+q.w*q.w)+v.y*(2*q.x*q.y-2*q.w*q.z)+v.z*(2*q.x*q.z+2*q.w*q.y),
      v.x*(2*q.w*q.z+2*q.x*q.y)+v.y*(q.w*q.w-q.x*q.x+q.y*q.y-q.z*q.z)+v.z*(2*q.y*q.z-2*q.w*q.x),
      v.x*(2*q.x*q.z-2*q.w*q.y)+v.y*(2*q.w*q.x+2*q.y*q.z)+v.z*(q.w*q.w-q.x*q.x-q.y*q.y+q.z*q.z)
    );
  }

  // TODO: testing
  // TODO: dfjfdkghdsjio8eruert uhewrjn w!
  // Rotate a quaternion by a vector (result = q + (1/2)*float4(0,v.x,v.y,v.z)*q)
  inline quaternion rotate(const quaternion &q, const float3 &v) {
    quaternion result(
      q.w + (0.5) * (-v.x * q.x - v.y * q.y - v.z * q.z),
      q.x + (0.5) * (v.x * q.w + v.y * q.z - v.z * q.y),
      q.y + (0.5) * (v.y * q.w + v.z * q.x - v.x * q.z),
      q.z + (0.5) * (v.z * q.w + v.x * q.y - v.y * q.x)
    );
    result.normalize();
    return result;
  }

  template<typename T> matrix3 quaternionToMatrix(const Quaternion<T> &q) {
      matrix3 m;
      // i hat
      m.data[0][0] = q.x*q.x-q.y*q.y-q.z*q.z+q.w*q.w;
      m.data[1][0] = 2*q.w*q.z+2*q.x*q.y;
      m.data[2][0] = 2*q.x*q.z-2*q.w*q.y;
      // j hat
      m.data[0][1] = 2*q.x*q.y-2*q.w*q.z;
      m.data[1][1] = q.w*q.w-q.x*q.x+q.y*q.y-q.z*q.z;
      m.data[2][1] = 2*q.w*q.x+2*q.y*q.z;
      // k hat
      m.data[0][2] = 2*q.x*q.z+2*q.w*q.y;
      m.data[1][2] = 2*q.y*q.z-2*q.w*q.x;
      m.data[2][2] = q.w*q.w-q.x*q.x-q.y*q.y+q.z*q.z;

      return m;
  }
}

#endif