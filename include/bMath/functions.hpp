#ifndef BMATH_FUNCTIONS
#define BMATH_FUNCTIONS

#include "vector.hpp"
#include "matrix.hpp"

namespace bMath {
  // TODO: Generalize vector transformation operations to any type not just floats

  // optimized 3x3 vector3 transformation
  float3 operator*(const float3 &v, const Matrix3 &m) {
    return float3(
      v.x*m(0,0)+v.y*m(0,1)+v.z*m(0,2),
      v.x*m(1,0)+v.y*m(1,1)+v.z*m(1,2),
      v.x*m(2,0)+v.y*m(2,1)+v.z*m(2,2)
    );
  }

  // optimized 4x4 vector3 transformation
  float3 operator*(const float3 &v, const Matrix4 &m) {
    return float3(
      v.x*m(0,0)+v.y*m(0,1)+v.z*m(0,2)+m(0,3),
      v.x*m(1,0)+v.y*m(1,1)+v.z*m(1,2)+m(1,3),
      v.x*m(2,0)+v.y*m(2,1)+v.z*m(2,2)+m(2,3)
    );
  }

  // optimized 4x4 vector4 transformation
  float4 operator*(const float4 &v, const Matrix4 &m) {
    return float4(
      v.x*m(0,0)+v.y*m(0,1)+v.z*m(0,2)+v.w*m(0,3),
      v.x*m(1,0)+v.y*m(1,1)+v.z*m(1,2)+v.w*m(1,3),
      v.x*m(2,0)+v.y*m(2,1)+v.z*m(2,2)+v.w*m(2,3),
      v.x*m(3,0)+v.y*m(3,1)+v.z*m(3,2)+v.w*m(3,3)
    );
  }
}

#endif