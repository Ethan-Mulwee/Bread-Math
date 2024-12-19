#ifndef BMATH_QUATERNION
#define BMATH_QUATERNION

#include "vector.hpp"

namespace bm {
  template<typename T>
  struct quaternion {
    union {
      vector<T,4> vec;
      struct {
        T x, y, z, w;
      };
    };

    quaternion() {}

    quaternion(T w, T x, T y, T z) {
      vec.x = x; vec.y = y; vec.z = z; vec.w = w;
    }

    quaternion(T angle, vector<T,3> axis) {
      axis.normalize();
      vec.w = cos(angle/2);
      auto s = sin(angle/2);
      vec.x = s*axis.x;
      vec.y = s*axis.y;
      vec.z = s*axis.z;
    }

    quaternion(vector<T,4> v) : vec(v) {}

    // TODO: testing not sure if that really should be *2
    T Angle() {
      return std::acos(vec.w)*2;
    }

    // TODO: testing
    vector<T,3> Axis() {
      T angle = (*this).Angle();
      T s = sin(angle/2);
      return vector<T,3>(vec.x/s,vec.y/s,vec.z/s);
    }

    T length() {
      return sqrt(x*x+y*y+z*z+w*w);
    }

    void normalize() {
      vec.normalize();
    }
  };


}

#endif