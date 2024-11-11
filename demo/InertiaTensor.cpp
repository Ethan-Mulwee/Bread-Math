#include "bMath/bMath.hpp"
#include "bMath/ext/iostream.hpp"

// g++ InertiaTensor.cpp -I../include

using namespace bMath;

int main() {
  Matrix3 cylTensor = InertiaTensorCylinder(1,1,1);
  std::cout << cylTensor << "\n";
}