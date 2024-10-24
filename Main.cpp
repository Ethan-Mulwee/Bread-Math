#include <iostream>
#include "bMath/bMath.hpp"

using namespace bMath;

int main() {
    Vector3 vec(4,5,6);
    vec.normalize();
    std::cout << vec.x << ", " <<  vec.y << ", " << vec.z << std::endl;

    Matrix<2,2> mat = Matrix<2,2>();
    mat.data[1][1] = 2;
    Matrix<2,2> mat2 = Matrix<2,2>();
    mat2.data[1][1] = 3;
    Matrix mat3 = mat + mat2;
    std::cout << mat3.data[1][1] << std::endl;
}