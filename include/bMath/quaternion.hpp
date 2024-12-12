#ifndef BMATH_QUATERNION
#define BMATH_QUATERNION

#include "vector.hpp"

namespace bMath {
  template<typename T>
  struct Quaternion {
    Vector<T,4> data;

    Quaternion(T w, T x, T y, T z) {
      data.x = x; data.y = y; data.z = z; data.w = w;
    }

    Quaternion(T angle, Vector<T,3> axis) {
      axis.normalize();
      data.w = cos(angle/2);
      auto s = sin(angle/2);
      data.x = s*axis.x;
      data.y = s*axis.y;
      data.z = s*axis.z;
    }

    float Angle() {
      return std::acos(data.w);
    }
  };


}

#endif