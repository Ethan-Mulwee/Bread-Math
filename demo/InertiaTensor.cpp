#include "bMath/bMath.hpp"
#include "bMath/ext/iostream.hpp"

// g++ InertiaTensor.cpp -I../include

using namespace bm;

int main() {
  matrix3 cylTensor = InertiaTensorCylinder(1,1,1);
  std::cout << cylTensor << "\n";
}