#ifndef BMATH_FUNCTIONS
#define BMATH_FUNCTIONS

#include "vector.hpp"
#include "matrix.hpp"

namespace bMath {
  // optimized 3x3 vector transformation
  Vector<float,3> operator*(const Vector<float,3> &v, const Matrix<float,3,3> &m) {
  return float3(
    v.x*m(0,0)+v.y*m(0,1)+v.z*m(0,2),
    v.x*m(1,0)+v.y*m(1,1)+v.z*m(1,2),
    v.x*m(2,0)+v.y*m(2,1)+v.z*m(2,2)
  );
}
}

#endif