#include "bMath/Geometry.hpp"
#include "bMath/bMath.hpp"
#include <iostream>

using namespace bMath;

int main() {
  Matrix<float, 2, 3> m1(
      5, 6, 2,
      0, 2, 1
  );
  Matrix<float, 3, 2> m2(
      10, 4,
      0, 4,
      9, 1
  );
  Triangle tri(float3(1,-1,0),float3(1,2,2),float3(4,0,0));
  Ray ray(float3(-1,-2,2),float3(1,1,-0.5));
  RayIntersection inter = Raycast(ray, tri);
  std::cout << inter.hit;
  std::cout << m1 * m2 << "\n";
}
