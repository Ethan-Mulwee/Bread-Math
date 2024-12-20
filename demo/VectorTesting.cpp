#include "bMath/bMath.hpp"
#include "bMath/ext/iostream.hpp"
#include <chrono>

using namespace bMath;

// g++ VectorTesting.cpp -I../include

int main() {
  // Test for transforming a vector3 by a matrix 3x3

  float3 v1(4,5,6);
  float3 v2(4,5,6);
  float4 v3(1,2,3,4);

  std::cout << v1.xy << "\n";
  std::cout << v3.xyz << "\n";

  // Performance testing

  auto start = std::chrono::high_resolution_clock::now();

  for (int i = 0; i < 1000000; i++) {
    v1+v2;
  }

  auto end = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double> elapsed = end - start;
  std::cout << "Elapsed time: " << elapsed.count() << " seconds" << std::endl;
}