#include <iostream>
#include "bMath/bMath.hpp"

using namespace bMath;

int main() {
    Vector3 vec(4,5,6);
    vec.normalize();
    std::cout << vec.x << ", " <<  vec.y << ", " << vec.z << std::endl;
}