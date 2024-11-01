#ifndef BMATH_MATRIX
#define BMATH_MATRIX

#include <assert.h>
#include <iostream>

namespace bMath {
template <typename T, int rows, int cols> struct Matrix {
  T data[rows][cols] = {};

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
  template<int Mrows, int Mcols>
  Matrix<T, rows, Mcols> operator*(Matrix<T, Mrows, Mcols> &m) {
    Matrix<T, rows, Mcols> result;
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < Mcols; j++) {
        float sum = 0;
        for (int k = 0; k < cols; k++) {
          sum += (*this)(i,k)*m(k,j);
        }
        result(i,j) = sum;
      }
    }
    return result;
  }
};
// TODO: Find the biggest number in the matrix and add spaces accordingly so all rows are of equal length
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
