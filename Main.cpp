#include "bMath/Matrix.hpp"
#include "bMath/Vector.hpp"
#include <iostream>

using namespace bMath;

int main() {
  Matrix<float,3,3> testMat;
  std::cout << testMat[0][0] << "\n";
}
