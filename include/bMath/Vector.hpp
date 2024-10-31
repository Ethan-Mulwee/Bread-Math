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
  // Normalize the vector
  void normalize() {
    float mag = (*this).magnitude();
    for (int i = 0; i < n; i++) {
      data[i] = data[i] * (float)1 / mag;
    }
  }
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

  float magnitude() const {
    float total;
    for (int i = 0; i < 2; i++) {
      total += data[i] * data[i];
    }
    return sqrt(total);
  }

  // Normalize the vector
  void normalize() {
    float mag = (*this).magnitude();
    for (int i = 0; i < 2; i++) {
      data[i] = data[i] * (float)1 / mag;
    }
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

  float magnitude() const {
    float total;
    for (int i = 0; i < 3; i++) {
      total += data[i] * data[i];
    }
    return sqrt(total);
  }

  // Normalize the vector
  void normalize() {
    float mag = (*this).magnitude();
    for (int i = 0; i < 3; i++) {
      data[i] = data[i] * (float)1 / mag;
    }
  }
};
template <> struct Vector<float, 4> {
  union {
    float data[4];
    struct {
      float w, x, y, z;
    };
  };

  template <typename... Args> Vector(Args... args) : data{(float)args...} {}

  float &operator[](int i) { return data[i]; }

  float operator[](int i) const { return data[i]; }

  float magnitude() const {
    float total;
    for (int i = 0; i < 4; i++) {
      total += data[i] * data[i];
    }
    return sqrt(total);
  }

  // Normalize the vector
  void normalize() {
    float mag = (*this).magnitude();
    for (int i = 0; i < 4; i++) {
      data[i] = data[i] * (float)1 / mag;
    }
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
// slerp between two quaternions
float4 slerp(const float4 &a, const float4 &b, float t) {
  // Do stuff
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

template <typename T, int n> Vector<T, n> normalize(const Vector<T, n> &a) {
  float mag = a.magnitude();
  Vector<T, n> result;
  for (int i = 0; i < n; i++) {
    result[i] = a[i] * (float)1 / mag;
  }
  return result;
}
// TODO
float4 QuaternionAxisAngle(const float angle, const float3 &axis) {
  return float4(std::cos(angle * 0.5), std::sin(angle * 0.5) * axis.x,
                std::sin(angle * 0.5) * axis.y, std::sin(angle * 0.5) * axis.z);
}

// TODO
// Rotate a vector by a quaternion
float3 rotate(const float3 &v, const float4 &q) {}

// TODO
// Rotate a quaternion by a vector
float4 rotate(const float4 &q, const float3 &v) {}

} // namespace bMath

#endif
