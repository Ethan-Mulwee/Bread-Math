#include <iostream>
#include "bMath/bMath.hpp"

using namespace bMath;

int main() {
    Quaternion q = QuaternionFromAxisAngle(M_PI/4, Vector3(1,1,1));
    q.log();
}