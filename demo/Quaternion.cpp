#include "bMath/bMath.hpp"
#include "bMath/ext/iostream.hpp"

using namespace bMath;

// g++ Quaternion.cpp -I../include

int main() {
    quaternion q((float)M_PI*0.5f, float3(0,1,0));
    
    std::cout << "q: " << q << "\n";
    std::cout << "converted back and forth: " << matrixToQuaternion(quaternionToMatrix(q)) << "\n";
}