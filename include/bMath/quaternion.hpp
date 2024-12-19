#ifndef BMATH_QUATERNION
#define BMATH_QUATERNION

#include "vector.hpp"

namespace bm {
  template<typename T>
  struct quaternion {
    vector<T,4> data;

    quaternion() {}

    quaternion(T w, T x, T y, T z) {
      data.x = x; data.y = y; data.z = z; data.w = w;
    }

    quaternion(T angle, vector<T,3> axis) {
      axis.normalize();
      data.w = cos(angle/2);
      auto s = sin(angle/2);
      data.x = s*axis.x;
      data.y = s*axis.y;
      data.z = s*axis.z;
    }

    quaternion(vector<T,4> v) : data(v) {}

    // TODO: testing not sure if that really should be *2
    T Angle() {
      return std::acos(data.w)*2;
    }

    // TODO: testing
    vector<T,3> Axis() {
      T angle = (*this).Angle();
      T s = sin(angle/2);
      return vector<T,3>(data.x/s,data.y/s,data.z/s);
    }
  };


}

#endif