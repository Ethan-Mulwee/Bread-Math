#ifndef BMATH_QUATERNION
#define BMATH_QUATERNION

#include "vector.hpp"

namespace bMath {
  template<typename T>
  struct Quaternion {
    union {
      Vector<T,4> vec;
      struct {
        T x, y, z, w;
      };
    };

    Quaternion() {}

    Quaternion(T w, T x, T y, T z) : w(w), x(x), y(y), z(z) {}

    Quaternion(T angle, Vector<T,3> axis) {
      axis.normalize();
      vec.w = cos(angle/2);
      auto s = sin(angle/2);
      vec.x = s*axis.x;
      vec.y = s*axis.y;
      vec.z = s*axis.z;
    }

    Quaternion(Vector<T,4> v) : vec(v) {}

    // Returns angle of rotation in radians
    T angle() {
      return std::acos(vec.w)*2;
    }

    Vector<T,3> axis() {
      T angle = (*this).angle();
      T s = sin(angle/2);
      return Vector<T,3>(vec.x/s,vec.y/s,vec.z/s);
    }

    T length() {
      return sqrt(x*x+y*y+z*z+w*w);
    }

    void normalize() {
      vec.normalize();
    }
  };

  typedef Quaternion<float> quaternion;
}

#endif