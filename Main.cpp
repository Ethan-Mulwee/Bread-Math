#include "bMath/Matrix.hpp"
#include "bMath/Vector.hpp"
#include <iostream>

using namespace bMath;

int main() {
  Matrix<float, 3, 3> m1(
      5, 6, 2,
      0, 2, 1,
      9, 2, 4
  );
  Matrix<float, 3, 3> m2(
      10, 4, 2,
      0, 4, 1,
      9, 1, 2
  );

  std::cout << m1 * m2 << "\n";
}
