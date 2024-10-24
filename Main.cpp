#include <iostream>
#include "bMath/bMath.hpp"

using namespace bMath;

int main() {
    // Vector3 vec(4,5,6);
    // vec.normalize();
    // std::cout << vec.x << ", " <<  vec.y << ", " << vec.z << std::endl;

    // Matrix<2,2> mat = Matrix<2,2>();
    // mat.data[1][1] = 2;
    // Matrix<2,2> mat2 = Matrix<2,2>();
    // mat2.data[1][1] = 3;
    // Matrix mat3 = mat + mat2;
    // std::cout << mat3.data[1][1] << std::endl;

    // Matrix mat4 = mat * mat2;
    // std::cout << mat4.data[1][1] << std::endl;

    Matrix mat5 = Matrix<2,3>();
    mat5.data[0][0] = 4;
    mat5.data[0][1] = 4;
    mat5.data[0][2] = 4;
    mat5.data[1][0] = 4;
    mat5.data[1][1] = 4;
    mat5.data[1][2] = 4;
    mat5.log();
    Matrix mat6 = Matrix<3,2>();
    mat6.data[0][0] = 3;
    mat6.data[0][1] = 3;
    mat6.data[1][0] = 3;
    mat6.data[1][1] = 3;
    mat6.data[2][0] = 3;
    mat6.data[2][1] = 3;
    mat6.log();


    Matrix mat7 = mat6*mat5;
    mat7.log();

    Quaternion q(4,3,2,1);
}