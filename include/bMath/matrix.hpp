#ifndef BMATH_MATRIX
#define BMATH_MATRIX

#include <assert.h>

namespace bMath {
template <typename T, int rows, int cols> struct Matrix {
  T data[rows][cols] = {};

  Matrix() {}

  Matrix(T data[rows][cols]) : data(data) {}

  // TODO: Constructor for creating matrices from vectors

  template <typename... Args> Matrix(Args... args) : data{(T)args...} {}

  T* operator[](const int i) const { return data[i]; }

  T& operator() (const int i, const int j) {return data[i][j];}

  T operator() (const int i, const int j) const {return data[i][j];}

  // Return component wise addition of two matrices
  Matrix<T, rows, cols> operator+(const Matrix<T, rows, cols> &m) const {
    Matrix<T, rows, cols> newMat;
    for (int j = 0; j < cols; j++) {
      for (int i = 0; i < rows; i++) {
        newMat.data[i][j] = data[i][j] + m.data[i][j];
      }
    }
    return newMat;
  }

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

typedef Matrix<float, 2, 2> Matrix2;
typedef Matrix<float, 3, 3> Matrix3;
typedef Matrix<float, 4, 4> Matrix4;
typedef Matrix<float, 2, 2> float2x2;
typedef Matrix<float, 3, 3> float3x3;
typedef Matrix<float, 4, 4> float4x4;

// TODO: figure out how to make this for loop logic happen at compile time
template<typename T, int rows, int cols>
Matrix<T, rows, cols> transpose(Matrix<T, rows, cols> &m) {
  Matrix<T, rows, cols> result;
  for (int j = 0; j < cols; j++) {
    for (int i = 0; i < rows; i++) {
      result(j,i) = m(i,j);
    }
  }
  return result;
}

template<typename T, int rows, int cols>
Matrix<T,rows,cols> operator*(const Matrix<T,rows,cols> &m, const float s) {
  Matrix<T,rows,cols> result;
  for (int j = 0; j < cols; j++) {
    for (int i = 0; i < rows; i++) {
      result(i,j) = m(i,j) * s;
    }
  }
  return result;
}

template<typename T, int rows, int cols>
Matrix<T,rows,cols> operator*(const float s, const Matrix<T,rows,cols> &m) {
  Matrix<T,rows,cols> result;
  for (int j = 0; j < cols; j++) {
    for (int i = 0; i < rows; i++) {
      result(i,j) = m(i,j) * s;
    }
  }
  return result;
}

inline Matrix3 transpose(const Matrix3 &m) {
  return Matrix3(
    m(0,0), m(1,0), m(2,0),
    m(0,1), m(1,1), m(2,1),
    m(0,2), m(1,2), m(2,2)
  );
}

inline Matrix4 transpose(const Matrix4 &m) {
  return Matrix4(
    m(0,0), m(1,0), m(2,0), m(3,0),
    m(0,1), m(1,1), m(2,1), m(3,1),
    m(0,2), m(1,2), m(2,2), m(3,2),
    m(0,3), m(1,3), m(2,3), m(3,3)
  );
}

// TODO: add determiant functions

inline float det(const Matrix<float, 1,1> &m) {
  return m(0,0);
}

inline float det(const Matrix2 &m) {
  return m(0,0)*m(1,1)-m(0,1)*m(1,0);
}

inline float det(const Matrix3 &m) {
  // taken from https://www.geeksforgeeks.org/what-is-determinant-of-a-matrix/#determinant-of-a-3x3-matrix will need look into methods and math behind matrix determinants later
  return m(0,0)*(m(1,1)*m(2,2)-m(1,2)*m(2,1))-m(0,1)*(m(1,0)*m(2,2)-m(1,2)*m(2,0))+m(0,2)*(m(1,0)*m(2,1)-m(1,1)*m(2,0));
}

inline float det(const Matrix4 &m) {
  return 0;
}

// NOTE: this implmentation is rather inefficent but it works for the moment
template<typename T, int rows, int cols>
Matrix<T, rows-1, cols-1> submatrix(const Matrix<T,rows,cols> &m, const int row, const int col) {
  Matrix<T, rows-1, cols-1> result;
  int rowIndex = 0;
  int colIndex = 0;
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      if (j != col && i != row) {
        result(rowIndex,colIndex) = m(i,j);
        colIndex++;
        if (colIndex == cols-1) {
          colIndex = 0;
          rowIndex++;
        }
      }
    }
  }
  return result;
}

// Returns det of a submatrix of m
template <typename T, int rows, int cols>
float minor(const Matrix<T,rows,cols> &m, const int row, const int col) {
  return det(submatrix(m, row, col));
}

// cofactor matrix made by taking the deterimants of all minor matrices that compose the matrix 
// and multiping by a sign factor according to if the rows and or col is odd
inline Matrix2 cof(const Matrix2 &m) {
  return Matrix2(
    minor(m,0,0), -minor(m,0,1),
    -minor(m,1,0), minor(m,1,1)
  );
}

inline Matrix3 cof(const Matrix3 &m) {
  return Matrix3(
    minor(m,0,0), -minor(m,0,1), minor(m,0,2),
    -minor(m,1,0), minor(m,1,1), -minor(m,1,2),
    minor(m,2,0), -minor(m,2,1), minor(m,2,2)
  );
}

inline Matrix4 cof(const Matrix4 &m) {
  return Matrix4(
    
  );
}

// What if I created a function that takes in a function pointer and performs opts on all the elements like this

// transpose of the cofactor matrix
inline Matrix3 adjugate(const Matrix3 &m) {
  return Matrix3();
}


inline Matrix3 adjoint(const Matrix3 &m) {
  return Matrix3();
}

// TODO: add inverse functions
// NOTE: this function does not work probably at the moment, something is off with the cofactor matrix
inline Matrix3 inverse(const Matrix3 &m) {
  // taken from https://www.youtube.com/watch?v=srnaDoIKA-E 
  Matrix3 cofactor = cof(m);
  cofactor = transpose(cofactor);
  return (1/det(m))*cofactor;
}

// inline Matrix4 inverse(const Matrix4 &m) {
//   Matrix4 cofactor = cof(m);
//   cofactor = transpose(cofactor);
//   return (1/det(m))*cofactor;
// }

// TODO:
// B^-1MB
// B is the transformation of the object aka the transformation that takes the coords from world space ot local space
inline Matrix4 changeBasis(const Matrix4 &m, const Matrix4 &b) {
  return Matrix4(
    
  );
}

// TODO: Creates a rotation matrix from euler angles in the order of xyz
inline Matrix3 rotationMatrix(float x, float y, float z) {
  return Matrix3();
}




} // namespace bMath

#endif
