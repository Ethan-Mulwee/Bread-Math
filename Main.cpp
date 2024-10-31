#include "bMath/Vector.hpp"
#include <iostream>

using namespace bMath;

int main() {
  float3 test(2, 3, 4);
  std::cout << test << "\n";
  std::cout << test.x << "\n";

  float4 test2(5, 4, 24, 1);
  std::cout << test2.w << test2.z << "\n";

  float3 test3(1, 2, 3);
  float3 test4(3, 7, 1);
  std::cout << ((test3 - test4) * 3) << "\n";
  std::cout << test3.magnitude() << "\n";

  std::cout << cross(test3, test4) << "\n";
  std::cout << dot(test3, test4) << "\n";

  std::cout << max(test3, test4) << "\n";

  std::cout << lerp(test3, test4, 0.5) << "\n";

  std::cout << distance(test3, test4) << "\n";
}
