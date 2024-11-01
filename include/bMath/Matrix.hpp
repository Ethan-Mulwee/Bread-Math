#ifndef BMATH_MATRIX
#define BMATH_MATRIX

#include <assert.h>
#include <iostream>

namespace bMath {
template <typename T, int rows, int cols> struct Matrix {
  T data[rows][cols] = {};
  const static int r = rows;
  const static int c = cols;

  Matrix() {}

  Matrix(T data[rows][cols]) : data(data) {}

  template <typename... Args> Matrix(Args... args) : data{(T)args...} {}

  Matrix<T, rows, cols> operator+(const Matrix<T, rows, cols> &m) const {
    Matrix<T, rows, cols> newMat;
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
        newMat.data[i][j] = data[i][j] + m.data[i][j];
      }
    }
    return newMat;
  }
  // TODO:

  T* operator[](const int i) const { return data[i]; }

  T& operator() (const int i, const int j) {return data[i][j];}

  T operator() (const int i, const int j) const {return data[i][j];}

  // template <typename T> auto operator*(const T &m) const {
  //  assert(cols == m.r);
  //  Matrix<rows, m.c> newMat;
  //  for (int i = 0; i < rows; i++) {
  //    for (int j = 0; j < m.c; j++) {
  //      float total = 0;
  //      for (int k = 0; k < cols; k++) {
  //        total += data[i][k] * m.data[k][i];
  //      }
  //      newMat.data[i][j] = total;
  //    }
  //  }
  //  return newMat;
  // }

  void log() const {
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
        std::cout << data[i][j] << ", ";
      }
      std::cout << "\n";
    }
  }
};

template <typename T, int rows, int cols>
std::ostream &operator<<(std::ostream &os, const Matrix<T, rows, cols> &m) {
  for (int i = 0; i < rows; i++) {
    os << "|";
   for (int j = 0; j < cols; j++) {
      os << m(i,j) << ((j < cols-1) ? ", " : "");
    }
   os << "|" << "\n";
  }
 return os;
}
} // namespace bMath

#endif
