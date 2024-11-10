#ifndef BMATH_PHYSICS
#define BMATH_PHYSICS

#include "matrix.hpp"
#include "vector.hpp"

namespace bMath {
  Matrix3 IntertiaTensorCuboid(float mass, float dx, float dy, float dz) {
    float c = mass*((float)1/12);
    return Matrix3(
      c*(dy*dy+dz*dz), 0, 0,
      0, c*(dx*dx+dz*dz), 0,
      0, 0, c*(dx*dx+dy*dy)
    );
  }

  Matrix3 IntertiaTensorSphere(float mass, float radius) {
    float c = ((float)2/3)*mass*radius*radius;
    return Matrix3(
      c,0,0,
      0,c,0,
      0,0,c
    );
  }

  Matrix3 IntertiaTensorEllipsoid(float mass, float3 r1, float3 r2) {

  }
} // namespace bMath

#endif