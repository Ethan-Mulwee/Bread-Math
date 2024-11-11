#include <chrono>
#include <iostream>
#include "bMath/matrix.hpp"
#include "bMath/ext/iostream.hpp"

// g++ MatrixTesting.cpp -I../include

using namespace bMath;

int main() {
  // Performance testing
  Matrix<float, 3, 3> m1(
    5,4,3,
    5,4,3,
    5,4,3
  );

  std::cout << m1 << "\n";

  std::cout << transpose(m1) << "\n";

  auto start = std::chrono::high_resolution_clock::now();

  for (int i = 0; i < 1000000; i++) {
    transpose(m1);
  }

  auto end = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double> elapsed = end - start;
  std::cout << "Elapsed time: " << elapsed.count() << " seconds" << std::endl;
}