#include <chrono>
#include <iostream>
#include "bMath/matrix.hpp"
#include "bMath/ext/iostream.hpp"

// g++ MatrixTesting.cpp -I../include

using namespace bMath;

int main() {
  Matrix4 m(
    5,4,3,1,
    2,6,2,4,
    7,8,9,10,
    1,2,3,4
  );

  std::cout << det(m) << "\n";

  Matrix<float,5,5> m5(
    5,4,3,2,34,
    4,34,5,8,9,
    56,4,2,10,3,
    7,8,9,10,3,
    1,2,3,4,10
  );

  std::cout << det(m5) << "\n";

  Matrix<float,3,2> weirdMatrix(
    4,2,
    5,1,
    3,4
  );

  // std::cout << det(weirdMatrix) << "\n";

  auto start = std::chrono::high_resolution_clock::now();

  for (int i = 0; i < 100000; i++) {
    det(m5);
  }

  auto end = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double> elapsed = end - start;
  std::cout << "Elapsed time: " << elapsed.count() << " seconds" << std::endl;
}