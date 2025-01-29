#include "bMath/bMath.hpp"
#include "bMath/ext/iostream.hpp"

using namespace bMath;

// g++ Quaternion.cpp -I../include

int main() {
    quaternion q((float)M_PI*0.5f, float3(0,1,0));
    matrix3 mat = quaternionToMatrix(q);
    
    std::cout << "q: " << q << "\n";
    std::cout << "converted back and forth: " << basisToQuaternion(mat.col(0),mat.col(1),mat.col(2)) << "\n";
}