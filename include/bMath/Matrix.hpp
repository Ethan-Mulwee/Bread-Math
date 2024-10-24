#ifndef BMATH_MATRIX
#define BMATH_MATRIX

#include <assert.h>

namespace bMath {
    template <int rows, int cols>
    struct Matrix {
        float data[rows][cols] = {};
        const int r = rows; const int c = cols;

        Matrix() {}

        Matrix operator+(const Matrix &m) const {
            assert(rows == m.r && c == m.c);
            Matrix<rows,cols> newMat;
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    newMat.data[i][j] = data[i][j] + m.data[i][j];
                }
            }
            return newMat;
        }
    };
}

#endif