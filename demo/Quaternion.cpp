#include "bMath/bMath.hpp"
#include "bMath/ext/iostream.hpp"

using namespace bm;

// g++ Quaternion.cpp -I../include

int main() {
  Quaternion q((float)M_PI*0.5f, float3(0,1,0));
  std::cout << q << "\n";
  std::cout << "Rotation angle: " << q.angle() << "\n";
  std::cout << "Rotation axis: " << q.axis() << "\n";
}