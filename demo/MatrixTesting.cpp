#include <chrono>
#include <iostream>
#include "bMath/matrix.hpp"
#include "bMath/ext/iostream.hpp"

// g++ MatrixTesting.cpp -I../include

using namespace bMath;

int main() {
  // Performance testing
  Matrix3 m1(
    2,4,3,
    5,2,3,
    5,4,2
  );

  Matrix2 m2(
    1,2,
    3,4
  );

  Matrix2 m3 = submatrix(m1,0,0);
  float deterimant = det(m3);

  std::cout << m3 << "\n";
  std::cout << deterimant << "\n";
  std::cout << cof(m1) << "\n";
  std::cout << inverse(m1) << "\n";

  // Matrix3 m2(
  //   2,0,0,
  //   0,2,0,
  //   0,0,2
  // );

  // Matrix3 m3 = inverse(m1);

  // std::cout << m1 << "\n";
  // std::cout << m3 << "\n";
  // std::cout << m3*m1 << "\n";

  // auto start = std::chrono::high_resolution_clock::now();

  // for (int i = 0; i < 1000000; i++) {
  //   transpose(m1);
  // }

  // auto end = std::chrono::high_resolution_clock::now();
  // std::chrono::duration<double> elapsed = end - start;
  // std::cout << "Elapsed time: " << elapsed.count() << " seconds" << std::endl;
}