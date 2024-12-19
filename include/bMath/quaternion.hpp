#ifndef BMATH_QUATERNION
#define BMATH_QUATERNION

#include "vector.hpp"

namespace bm {
  template<typename T>
  struct Quaternion {
    Vector<T,4> data;

    Quaternion() {}

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

    Quaternion(Vector<T,4> v) : data(v) {}

    // TODO: testing not sure if that really should be *2
    T Angle() {
      return std::acos(data.w)*2;
    }

    // TODO: testing
    Vector<T,3> Axis() {
      T angle = (*this).Angle();
      T s = sin(angle/2);
      return Vector<T,3>(data.x/s,data.y/s,data.z/s);
    }
  };


}

#endif