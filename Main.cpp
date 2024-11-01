#include "bMath/Matrix.hpp"
#include "bMath/Vector.hpp"
#include <iostream>

using namespace bMath;

int main() {
  Matrix<float,3,3> testMat(
    5,3,2,
    0,2,1,
    9,2,4
  );
  std::cout << testMat << "\n";
  testMat(1,1) = 4;
  std::cout << testMat << "\n";
}
