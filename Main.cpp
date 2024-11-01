#include "bMath/Matrix.hpp"
#include "bMath/Vector.hpp"
#include <iostream>

using namespace bMath;

int main() {
  Matrix<float, 2, 3> m1(
      5, 6, 2,
      0, 2, 1
  );
  Matrix<float, 3, 2> m2(
      10, 4,
      0, 4,
      9, 1
  );

  std::cout << m1 * m2 << "\n";
}
