#ifndef BMATH_VECTOR
#define BMATH_VECTOR

#include "float.hpp"
#include "fwd.hpp"
#include <algorithm>
#include <math.h>

namespace bm {
template <typename T, std::size_t N> struct vector {
  T data[N];

  template <typename... Args> vector(Args... args) : data{(T)args...} {}

  T &operator[](int i) { return data[i]; }

  T operator[](int i) const { return data[i]; }

  float length() {
    float total = 0;
    for (int i = 0; i < N; i++) {
      total += data[i] * data[i];
    }
    return sqrt(total);
  }

  // TODO
  // Normalize the vector
  void normalize() {
    float mag = (*this).length();
    for (int i = 0; i < N; i++) {
      data[i] = data[i] * (float)1 / mag;
    }
  }
};

template <> struct vector<float, 2> {
  union {
    float data[2];
    struct {
      float x, y;
    };
  };

  // TODO: Add a marco to automatically create these duplicate defs
  
  // TODO: Constructor to create vectors from smaller vectors like a vec3 from a vec2

  template <typename... Args> vector(Args... args) : data{(float)args...} {}

  float &operator[](int i) { return data[i]; }

  float operator[](int i) const { return data[i]; }

  float length() const {
    float total = 0;
    for (int i = 0; i < 2; i++) {
      total += data[i] * data[i];
    }
    return sqrt(total);
  }

  // Normalize the vector
  void normalize() {
    float mag = (*this).length();
    for (int i = 0; i < 2; i++) {
      data[i] = data[i] * (float)1 / mag;
    }
  }
};

template <> struct vector<float, 4> {
  union {
    float data[4];
    struct {
      float x, y, z, w;
    };
  };

  // TODO implict conversion
  // Vector(Quaternion<float> q) : data(q.data) {}

  template <typename... Args> vector(Args... args) : data{(float)args...} {}

  float &operator[](int i) { return data[i]; }

  float operator[](int i) const { return data[i]; }

  float length() const {
    float total = 0;
    for (int i = 0; i < 4; i++) {
      total += data[i] * data[i];
    }
    return sqrt(total);
  }

  // Normalize the vector
  void normalize() {
    float mag = (*this).length();
    for (int i = 0; i < 4; i++) {
      data[i] = data[i] * (float)1 / mag;
    }
  }
};

// TODO: template specialization includes other types
template <> struct vector<float, 3> {
  union {
    float data[3];
    struct {
      float x, y, z;
    };
    vector<float, 2> xy;
  };

  template <typename... Args> vector(Args... args) : data{(float)args...} {}

  // TODO: Add support for converting bigger vector types to smaller vector types
  vector(vector<float,4> vec) : data{vec.data[0],vec.data[1],vec.data[2]} {}

  float &operator[](int i) { return data[i]; }

  float operator[](int i) const { return data[i]; }

  float length() const {
    float total = 0;
    for (int i = 0; i < 3; i++) {
      total += data[i] * data[i];
    }
    return sqrt(total);
  }

  // Normalize the vector
  void normalize() {
    float mag = (*this).length();
    for (int i = 0; i < 3; i++) {
      data[i] = data[i] * (float)1 / mag;
    }
  }
};

typedef vector<double, 2> double2;
typedef vector<double, 3> double3;
typedef vector<double, 4> double4;

typedef vector<float, 2> float2;
typedef vector<float, 3> float3;
typedef vector<float, 4> float4;

typedef vector<int, 2> int2;
typedef vector<int, 3> int3;
typedef vector<int, 4> int4;

template <typename T, std::size_t N>
vector<T, N> operator+(const vector<T, N> &a, const vector<T, N> &b) {
  vector<T, N> result;
  for (int i = 0; i < N; i++) {
    result[i] = a[i] + b[i];
  }
  return result;
}

template <typename T, std::size_t N>
void operator+=(vector<T, N> &a, const vector<T, N> &b) {
  for (int i = 0; i < N; i++) {
    a[i] += b[i];
  }
}

template <typename T, std::size_t N>
vector<T, N> operator-(const vector<T, N> &a, const vector<T, N> &b) {
  vector<T, N> result;
  for (int i = 0; i < N; i++) {
    result[i] = a[i] - b[i];
  }
  return result;
}

template <typename T, std::size_t N>
void operator-=(vector<T, N> &a, const vector<T, N> &b) {
  for (int i = 0; i < N; i++) {
    a[i] -= b[i];
  }
}

// Returns vector scaled by scalar
template <typename T, std::size_t N>
vector<T, N> operator*(const vector<T, N> &a, const float b) {
  vector<T, N> result;
  for (int i = 0; i < N; i++) {
    result[i] = a[i] * b;
  }
  return result;
}

// Returns vector scaled by scalar
template <typename T, std::size_t N>
vector<T, N> operator*(const float a, const vector<T, N> &b) {
  vector<T, N> result;
  for (int i = 0; i < N; i++) {
    result[i] = a * b[i];
  }
  return result;
}

// Returns vector divided by scalar component wise
template <typename T, std::size_t N>
vector<T, N> operator/(const vector<T, N> &a, const float b) {
  vector<T, N> result;
  for (int i = 0; i < N; i++) {
    result[i] = a[i] / b;
  }
  return result;
} 

// Returns vector multipled component wise (hadamard product)
template <typename T, std::size_t N>
vector<T, N> operator*(const vector<T,N> &a, const vector<T,N> &b) {
  vector<T,N> result;
  for (int i = 0; i < N; i++) {
    result[i] = a[i]*b[i];
  }
}

// Multiples vector component wise by another vector
template <typename T, std::size_t N>
vector<T, N> operator*=(vector<T,N> &a, const vector<T,N> &b) {
  for (int i = 0; i < N; i++) {
    a[i] *= b[i];
  }
}

// Transforms vector by a matrix (assuming column vector)
template <typename T, std::size_t N, int rows>
vector<T, rows> operator*(const vector<T,N> &v, const matrix<T,rows,N> &m) {
  vector<T, rows> result;
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < N; j++) {
      result[i] += v[j]*m(i,j);
    }
  }
  return result;
}

// TODO: make this less slow?
// Transforms vector by a matrix bigger than the source vector (just fills 1s) (assuming column vector)
template <typename T, std::size_t N, int cols, int rows>
vector<T, N> operator*(const vector<T,N> &v, const matrix<T,rows,cols> &m) {
  vector<T, N> result;
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      if (i >= N) return result;
      T cord;
      if (j < N) cord = v[j];
      else cord = 1;
      result[i] += cord*m(i,j);
    }
  }
  return result;
}

// Returns vector transformed by matrix (will shrink dimension of vector of transformation does so)
// template <typename T, std::size_t n, int cols>
// Vector<T, cols> transform(const Vector<T,n> &v, const Matrix<T,n,cols> &m) {
//   Vector<T, cols> result;
// }

template <typename T, std::size_t N>
float lengthSquared(const vector<T,N> &v) {
  float total;
  for (int i = 0; i < N; i++) {
    total += v[i]*v[i];
  }
  return total;
} 

template <typename T, std::size_t N>
float dot(const vector<T, N> &a, const vector<T, N> &b) {
  float result = 0;
  for (int i = 0; i < N; i++) {
    result += a[i] * b[i];
  }
  return result;
}

// TODO: general wedge product
template<typename T>
vector<T,3> wedgeProduct(const vector<T,3> &a, const vector<T,3> &b) {
  return vector<T,3>();
}

// Just does geometric product for vectors of size 3 for now
// TODO: figure out how to generalize to any dim
template <typename T>
vector<T,4> geometricProduct(const vector<T,3> &a, const vector<T,3> &b) {
  return vector<T,4>(
    a.y*b.z-a.z*b.z,
    a.z*b.x-a.x*b.z,
    a.x*b.y-a.y*b.x,
    a.x*b.x+a.y*b.y+a.z*b.z
  );
}

// TODO: test on non unit vectors
template <typename T>
vector<T,4> rotationBetween(const vector<T,3> &a, const vector<T,3> &b) {
  vector<T,3> axis = cross(a,b);
  vector<T,4> Quaternion(
    axis.x,axis.y,axis.z, dot(a,b)+1
  );
  return normalized(Quaternion);
}

template <typename T>
vector<T, 3> cross(const vector<T, 3> &a, const vector<T, 3> &b) {
  return vector<T, 3>(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x);
}

template <typename T>
vector<T, 3> project(const vector<T, 3> &a, const vector<T, 3> &b) {
  return (dot(a,b)/dot(b,b))*b;
}

template <typename T>
vector<T, 3> projectOnPlane(const vector<T, 3> &v, const vector<T, 3> &n) {
  return v-project(v,n);
}

template <typename T, std::size_t N>
vector<T, N> max(const vector<T, N> &a, const vector<T, N> &b) {
  vector<T, N> result;
  for (int i = 0; i < N; i++) {
    result[i] = std::max(a[i], b[i]);
  }
  return result;
}

template <typename T, std::size_t N>
vector<T, N> min(const vector<T, N> &a, const vector<T, N> &b) {
  vector<T, N> result;
  for (int i = 0; i < N; i++) {
    result[i] = std::min(a[i], b[i]);
  }
  return result;
}

template <typename T, std::size_t N>
vector<T, N> lerp(const vector<T, N> &a, const vector<T, N> &b, const float t) {
  vector<T, N> result;
  for (int i = 0; i < N; i++) {
    result[i] = lerp(a[i], b[i], t);
  }
  return result;
}

// TODO
// slerp between two quaternions
inline float4 slerp(const float4 &a, const float4 &b, float t) {
  return float4();
}

// TODO
// Clamp length of vector
template <typename T, std::size_t N>
vector<T, N> clamp(const vector<T, N> &a, float b) {
  return vector<T,N>();
}

// TODO
// Clamp vector component wise
template <typename T, std::size_t N>
vector<T, N> clamp(const vector<T, N> &a, const vector<T, N>) {
  // std::clamp()
}

template <typename T, std::size_t N>
float distance(const vector<T, N> &a, const vector<T, N> &b) {
  return (a - b).length();
}

template <typename T, std::size_t N> vector<T, N> normalized(const vector<T, N> &a) {
  float len = a.length();
  vector<T, N> result;
  for (int i = 0; i < N; i++) {
    result[i] = a[i] * (float)1 / len;
  }
  return result;
}

// Rotate a vector by a quaternion
inline float3 rotate(const float3 &v, const float4 &q) {
  return float3(
    v.x*(q.x*q.x-q.y*q.y-q.z*q.z+q.w*q.w)+v.y*(2*q.x*q.y-2*q.w*q.z)+v.z*(2*q.x*q.z+2*q.w*q.y),
    v.x*(2*q.w*q.z+2*q.x*q.y)+v.y*(q.w*q.w-q.x*q.x+q.y*q.y-q.z*q.z)+v.z*(2*q.y*q.z-2*q.w*q.x),
    v.x*(2*q.x*q.z-2*q.w*q.y)+v.y*(2*q.w*q.x+2*q.y*q.z)+v.z*(q.w*q.w-q.x*q.x-q.y*q.y+q.z*q.z)
  );
}

// TODO: testing
// Rotate a quaternion by a vector (result = q + (1/2)*float4(0,v.x,v.y,v.z)*q)
inline float4 rotate(const float4 &q, const float3 &v) {
  float4 result(
    q.x + (0.5) * (v.x * q.w + v.y * q.z - v.z * q.y),
    q.y + (0.5) * (v.y * q.w + v.z * q.x - v.x * q.z),
    q.z + (0.5) * (v.z * q.w + v.x * q.y - v.y * q.x),
    q.w + (0.5) * (-v.x * q.x - v.y * q.y - v.z * q.z)
  );
  result.normalize();
  return result;
}

// Returns vector rotated some degrees along the x axis
inline float3 rotateX(const float3 &v, const float angle) {
  return float3(
    v.x, v.y*cos(angle)-v.z*sin(angle), v.y*sin(angle)+v.z*cos(angle)
  );
}

// Returns vector rotated some degrees along the y axis
inline float3 rotateY(const float3 &v, const float angle) {
  return float3(
    v.x*cos(angle)+v.z*sin(angle), v.y, v.z*cos(angle)-v.x*sin(angle)
  );
}

// Returns vector rotated some degrees along the z axis
inline float3 rotateZ(const float3 &v, const float angle) {
  return float3(
    v.x*cos(angle)-v.y*sin(angle), v.x*sin(angle)+v.y*cos(angle), v.z
  );
}
} // namespace bMath

#endif
