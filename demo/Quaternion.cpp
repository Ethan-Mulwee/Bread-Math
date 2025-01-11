#include "bMath/bMath.hpp"
#include "bMath/ext/iostream.hpp"

using namespace bMath;

// g++ Quaternion.cpp -I../include

int main() {
  quaternion q((float)M_PI*0.5f, float3(0,1,0));
  quaternion b(0,1,2,3);

  std::cout << "q: " << q << "\n";
  std::cout << "q rotated: " << q*vectorToQuaternion(float3(1,0,0)) << "\n";
  std::cout << "Rotation angle: " << q.angle() << "\n";
  std::cout << "Rotation axis: " << q.axis() << "\n";

  float3 v(2,3,4);
  std::cout << v*q << "\n";

  std::cout << quaternionToMatrix(q) << "\n";
  std::cout << v*quaternionToMatrix(q) << "\n";
}