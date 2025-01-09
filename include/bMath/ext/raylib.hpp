#ifndef BMATH_RAYLIB
#define BMATH_RAYLIB

#include <raylib.h>
#include "../vector.hpp"
#include "../matrix.hpp"

inline Vector3 toRay(const bMath::Vector<float,3> &v) {
  return Vector3{v.x,v.y,v.z};
}

inline Matrix toRay(const bMath::matrix4 &m) {
  return Matrix{
    m(0,0), m(0,1), m(0,2), m(0,3),
    m(1,0), m(1,1), m(1,2), m(1,3),
    m(2,0), m(2,1), m(2,2), m(2,3),
    m(3,0), m(3,1), m(3,2), m(3,3)
  };
}

inline Ray toRay(const bMath::Ray &ray) {
  return Ray{toRay(ray.p), toRay(ray.d)};
}

inline bMath::float2 toBread(const Vector2 &v) {
  return bMath::float2(v.x,v.y);
}

inline bMath::float3 toBread(const Vector3 &v) {
  return bMath::float3(v.x,v.y,v.z);
}

inline bMath::matrix4 toBread(const Matrix &m) {
  return bMath::matrix4(
    m.m0, m.m4, m.m8, m.m12,
    m.m1, m.m5, m.m9, m.m13,
    m.m2, m.m6, m.m10, m.m14,
    m.m3, m.m7, m.m11, m.m15
  );
}

inline bMath::Ray toBread(const Ray &ray) {
  return bMath::Ray(toBread(ray.position), toBread(ray.direction));
}

inline void drawVector(const bMath::float3 &v) {
  DrawLine3D(Vector3{0,0,0}, toRay(v), WHITE);
}

inline void drawVector(const bMath::float3 &v, Color color) {
  DrawLine3D(Vector3{0,0,0}, toRay(v), color);
}

inline void drawVector(const bMath::float3 &start, const bMath::float3 &v) {
  DrawLine3D(toRay(start), toRay(v), WHITE);
}

inline void drawVector(const bMath::float3 &start, const bMath::float3 &v, Color color) {
  DrawLine3D(toRay(start), toRay(v), color);
}

inline void drawBasis(const bMath::matrix3 &m) {
  drawVector(m.col(0), RED);
  drawVector(m.col(1), GREEN);
  drawVector(m.col(2), BLUE);
}

inline void drawBasis(const bMath::matrix3 &m, float scale) {
  drawVector(m.col(0)*scale, RED);
  drawVector(m.col(1)*scale, GREEN);
  drawVector(m.col(2)*scale, BLUE);
}

#endif