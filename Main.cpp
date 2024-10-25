#include <iostream>
#include "bMath/bMath.hpp"

using namespace bMath;

int main() {
    Triangle triangle(Vector3(1,0,-1), Vector3(1,2,2), Vector3(4,0,0));
    Ray ray(Vector3(-1,2,-2), Vector3(1,-0.5,1));

    RayIntersection intersection = Raycast(ray, triangle);
    std::cout << intersection.point << std::endl;

    Matrix<3,3> m;
    std::cout << m << std::endl;
}