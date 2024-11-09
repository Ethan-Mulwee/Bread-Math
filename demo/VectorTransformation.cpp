#include "bMath/bMath.hpp"
#include "bMath/iostream.hpp"

using namespace bMath;

// g++ VectorTransformation.cpp -I../include

int main() {
  Matrix3 m(
    2,0,0,
    0,2,0,
    0,0,2
  );

  float3 v(4,5,6);

  std::cout << "Matrix: \n" << m << "\n";
  std::cout << "Vector: " << v << "\n"; 
  std::cout << "Transformed Vector: " << (v*m) << "\n";
}