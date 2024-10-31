#ifndef BMATH_VECTOR
#define BMATH_VECTOR

#include "Float.hpp"
#include <algorithm>
#include <iostream>
#include <math.h>

namespace bMath {
template <typename T, int n> struct Vector {
  T data[n];

  template <typename... Args> Vector(Args... args) : data{(T)args...} {}

  T &operator[](int i) { return data[i]; }

  T operator[](int i) const { return data[i]; }

  float magnitude() {
    float total;
    for (int i = 0; i < n; i++) {
      total += data[i] * data[i];
    }
    return sqrt(total);
  }

  // TODO
  Vector<T, n> normalize() {
    float mag = (*this).magnitude();
    for (int i = 0; i < n; i++) {
      data[i] = data[i] * (float)1 / mag;
    }
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
  union {
    float data[2];
    struct {
      float x, y;
    };
  };

  template <typename... Args> Vector(Args... args) : data{(float)args...} {}

  float &operator[](int i) { return data[i]; }

  float operator[](int i) const { return data[i]; }

  float magnitude() {
    float total;
    for (int i = 0; i < 2; i++) {
      total += data[i] * data[i];
    }
    return sqrt(total);
  }
};
template <> struct Vector<float, 3> {
  union {
    float data[3];
    struct {
      float x, y, z;
    };
  };

  template <typename... Args> Vector(Args... args) : data{(float)args...} {}

  float &operator[](int i) { return data[i]; }

  float operator[](int i) const { return data[i]; }

  float magnitude() {
    float total;
    for (int i = 0; i < 3; i++) {
      total += data[i] * data[i];
    }
    return sqrt(total);
  }
};
template <> struct Vector<float, 4> {
  union {
    float data[4];
    struct {
      float x, y, z, w;
    };
  };

  template <typename... Args> Vector(Args... args) : data{(float)args...} {}

  float &operator[](int i) { return data[i]; }

  float operator[](int i) const { return data[i]; }

  float magnitude() {
    float total;
    for (int i = 0; i < 4; i++) {
      total += data[i] * data[i];
    }
    return sqrt(total);
  }
};

typedef Vector<float, 2> float2;
typedef Vector<float, 3> float3;
typedef Vector<float, 4> float4;

typedef Vector<int, 2> int2;
typedef Vector<int, 3> int3;
typedef Vector<int, 4> int4;

template <typename T, int n>
std::ostream &operator<<(std::ostream &os, const Vector<T, n> &v) {
  os << "(";
  for (int i = 0; i < n; i++) {
    os << v[i] << ((i != n - 1) ? ", " : "");
  }
  os << ")";
  return os;
}

template <typename T, int n>
Vector<T, n> operator+(const Vector<T, n> &a, const Vector<T, n> &b) {
  Vector<T, n> result;
  for (int i = 0; i < n; i++) {
    result[i] = a[i] + b[i];
  }
  return result;
}

template <typename T, int n>
Vector<T, n> operator-(const Vector<T, n> &a, const Vector<T, n> &b) {
  Vector<T, n> result;
  for (int i = 0; i < n; i++) {
    result[i] = a[i] - b[i];
  }
  return result;
}

template <typename T, int n>
Vector<T, n> operator*(const Vector<T, n> &a, const float b) {
  Vector<T, n> result;
  for (int i = 0; i < n; i++) {
    result[i] = a[i] * b;
  }
  return result;
}

template <typename T, int n>
float dot(const Vector<T, n> &a, const Vector<T, n> &b) {
  float result;
  for (int i = 0; i < n; i++) {
    result += a[i] * b[i];
  }
  return result;
}

template <typename T>
Vector<T, 3> cross(const Vector<T, 3> &a, const Vector<T, 3> &b) {
  return Vector<T, 3>(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z,
                      a.x * b.y - a.y * b.x);
}

template <typename T, int n>
Vector<T, n> max(const Vector<T, n> &a, const Vector<T, n> &b) {
  Vector<T, n> result;
  for (int i = 0; i < n; i++) {
    result[i] = std::max(a[i], b[i]);
  }
  return result;
}

template <typename T, int n>
Vector<T, n> min(const Vector<T, n> &a, const Vector<T, n> &b) {
  Vector<T, n> result;
  for (int i = 0; i < n; i++) {
    result[i] = std::min(a[i], b[i]);
  }
  return result;
}

template <typename T, int n>
Vector<T, n> lerp(const Vector<T, n> &a, const Vector<T, n> &b, const float t) {
  Vector<T, n> result;
  for (int i = 0; i < n; i++) {
    result[i] = lerp(a[i], b[i], t);
  }
  return result;
}

// TODO
// Clamp length of vector
template <typename T, int n>
Vector<T, n> clamp(const Vector<T, n> &a, float b) {}

// TODO
// Clamp vector component wise
template <typename T, int n>
Vector<T, n> clamp(const Vector<T, n> &a, const Vector<T, n>) {
  // std::clamp()
}

template <typename T, int n>
float distance(const Vector<T, n> &a, const Vector<T, n> &b) {
  return (a - b).magnitude();
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
} // namespace bMath

#endif
