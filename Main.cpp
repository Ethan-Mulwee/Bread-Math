#include <iostream>
#include "bMath/Vector.hpp"

using namespace bMath;

int main() {
    float3 test(2,3,4);
    std::cout << test << "\n";
    std::cout << test.x << "\n";

    float4 test2(5,4,24,1);
    std::cout << test2.w << test2.z << "\n";

    float3 test3(1,2,3);
    float3 test4(3,6,1);
    std::cout << test3+test4 << "\n";
}