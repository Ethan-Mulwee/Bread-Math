#include "bMath/Geometry.hpp"
#include "bMath/bMath.hpp"
#include <iostream>
#include <vector>

//#include <raylib.h>

using namespace bMath;

int main() {
  float3 a(2,3,4);
  float3 b(5,3,1);
  std::cout << dot(a,b) << "\n";
  std::cout << cross(a,b) << "\n";

  Matrix3 m(
    4,5.5,6,
    1,0,4.5,
    20,123.3,2
  );
  std::vector<Triangle> tris;
  Triangle tri(float3(1,0,-1), float3(1,2,2), float3(4,0,0));
  tris.push_back(tri);
  Ray ray(float3(-1,2,-2), float3(1,-0.5,1));

  RayIntersection inter = Raycast(ray, tris);

  std::cout << inter.hit << "\n";

  std::cout << m << "\n";
}
