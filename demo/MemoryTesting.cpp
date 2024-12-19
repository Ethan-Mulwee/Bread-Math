#include "bMath/bMath.hpp"
#include "bMath/ext/iostream.hpp"

// g++ MemoryTesting.cpp -I../include -g

using namespace bm;

int main() {
  int test = 9;
  vector<int, 3> test2 (4,5,6);
  matrix<int, 3,3> test4(
    1,2,3,
    4,5,6,
    7,8,9
  );
  int test3 = 2;
}