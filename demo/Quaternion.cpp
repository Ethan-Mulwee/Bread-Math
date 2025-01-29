#include "bMath/bMath.hpp"
#include "bMath/ext/iostream.hpp"

using namespace bMath;

// g++ Quaternion.cpp -I../include

int main() {
    quaternion from((float)M_PI*0.5f, float3(0,1,0));
    quaternion to((float)M_PI*0.6f, float3(0,1,0));
    quaternion rotation = to*from.inverse();


    std::cout << "q: " << from*rotation << "\n";
    std::cout << "rotation: " << rotation << "\n";
    std::cout << "Target: " << to << "\n";
    std::cout << "function's rotation output: " << rotationBetween(from, to) << "\n";
}