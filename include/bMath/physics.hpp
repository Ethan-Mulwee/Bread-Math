#ifndef BMATH_PHYSICS
#define BMATH_PHYSICS

#include "matrix.hpp"
#include "vector.hpp"

namespace bMath {
  // Following inertia tensor function's math for common shapes comes from: Game Physics Engine Development p.493-495

  // Returns the inertia tensor of a cuboid from the center of mass
  Matrix3 IntertiaTensorCuboid(float m, float dx, float dy, float dz) {
    float c = m*((float)1/12);
    return Matrix3(
      c*(dy*dy+dz*dz), 0, 0,
      0, c*(dx*dx+dz*dz), 0,
      0, 0, c*(dx*dx+dy*dy)
    );
  }

  // Returns the inertia tensor of a sphere from the center of mass 
  Matrix3 IntertiaTensorSphere(float m, float r) {
    float c = ((float)2/3)*m*r*r;
    return Matrix3(
      c,0,0,
      0,c,0,
      0,0,c
    );
  }

  // Returns the intertia tensor of a ellipsoid from the center of mass
  // m - mass, r - radii
  Matrix3 IntertiaTensorEllipsoid(float m, float3 r) {
    float c = ((float)1/5)*m;
    return Matrix3(
      c*(r.y*r.y+r.z*r.z),0,0,
      0,c*(r.x*r.x+r.z*r.z),0,
      0,0,c*(r.x*r.x+r.y*r.y)
    );
  }

  // Returns the intertia tensor of a cylidner from the center of mass
  // m - mass, h - height, r - radius 
  Matrix3 InertiaTensorCylinder(float m, float h, float r) {
    return Matrix3(
      (1/12.0f)*h*h+(1/4.0f)*m*r*r,0,0,
      0,(1/2.0f)*m*r*r,0,
      0,0,(1/12.0f)*h*h+(1/4.0f)*m*r*r
    );
  }

  // Returns the inertia tensor of a tube from the center of mass
  // m - mass, h - height, ro - outer radius, ri inner radius
  Matrix3 InertiaTensorTube(float m, float h, float ro, float ri) {
    return Matrix3(

    );
  }
} // namespace bMath

#endif