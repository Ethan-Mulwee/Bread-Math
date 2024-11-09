#include "bMath/bMath.hpp"
#include "bMath/iostream.hpp"

using namespace bMath;

// g++ VectorTransformation.cpp -I../include

int main() {
  Matrix3 m1(
    2,0,0,
    0,2,0,
    0,0,2
  );

  float3 v1(4,5,6);

  std::cout << "Matrix: \n" << m1 << "\n";
  std::cout << "Vector: " << v1 << "\n"; 
  std::cout << "Transformed Vector: " << (v1*m1) << "\n";

  Matrix4 m2(
    2,0,0,1,
    0,2,0,1,
    0,0,2,1,
    0,0,0,1
  );

  float3 v2(4,5,6);

  std::cout << "Matrix: \n" << m2 << "\n";
  std::cout << "Vector: " << v2 << "\n"; 
  std::cout << "Transformed Vector: " << (v2*m2) << "\n";
}