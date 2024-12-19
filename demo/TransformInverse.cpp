#include "bMath/matrix.hpp"
#include "bMath/ext/iostream.hpp"

using namespace bm;

int main() {
    matrix<float,3,1> m1(
        4,
        5,
        6
    );

    matrix<float,1,3> m2(
        -4,-5,-6
    );

    std::cout << m2*m1 << "\n";
}