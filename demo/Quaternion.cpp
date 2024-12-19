#include "bMath/bMath.hpp"
#include "bMath/ext/iostream.hpp"

using namespace bm;

// g++ Quaternion.cpp -I../include

int main() {
  quaternion<float> q(0.5,0.2,0.1,2);
  std::cout << q << "\n";
  std::cout << q.w << "\n";

  q.normalize();

  std::cout << q << "\n";

  std::cout << quaternionToMatrix(q) << "\n";
}