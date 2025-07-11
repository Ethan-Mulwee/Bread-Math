#ifndef BMATH_MATRIX
#define BMATH_MATRIX

#include <assert.h>
#include "vector.hpp"

namespace bMath {
template <typename T, int rows, int cols> struct Matrix {
  T data[rows][cols] = {};

  Matrix() {}

  Matrix(T data[rows][cols]) : data(data) {}

  // TODO: Constructor for creating matrices from vectors

  template <typename... Args> Matrix(Args... args) : data{(T)args...} {}

  T* operator[](const int i) {return data[i];}

  const T* operator[](const int i) const {return data[i];}

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
  Matrix<T, rows, Mcols> operator*(const Matrix<T, Mrows, Mcols> &m) const {
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

  // TODO: static_Assert j < cols?
  Vector<T, rows> col(const int j) const {
    Vector<T, rows> result;
    for (int i = 0; i < rows; i++) {
      result[i] = data[i][j];
    }
    return result;
  }

  static Matrix<T, rows, cols> identity() {
    Matrix<T, rows, cols> m;
    for (int i = 0; i < cols; i++) {
      m.data[i][i] = 1;
    }
    return m;
  }
};

typedef Matrix<float, 2, 2> matrix2;
typedef Matrix<float, 3, 3> matrix3;
typedef Matrix<float, 4, 4> matrix4;
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
void operator*=(Matrix<T,rows,cols> &m, const float s) {
  for (int j = 0; j < cols; j++) {
    for (int i = 0; i < rows; i++) {
      m[i][j] *= s;
    }
  }
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

inline matrix3 transpose(const matrix3 &m) {
  return matrix3(
    m(0,0), m(1,0), m(2,0),
    m(0,1), m(1,1), m(2,1),
    m(0,2), m(1,2), m(2,2)
  );
}

inline matrix4 transpose(const matrix4 &m) {
  return matrix4(
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

inline float det(const matrix2 &m) {
  return m(0,0)*m(1,1)-m(0,1)*m(1,0);
}

inline float det(const matrix3 &m) {
  // taken from https://www.geeksforgeeks.org/what-is-determinant-of-a-matrix/#determinant-of-a-3x3-matrix will need look into methods and math behind matrix determinants later
  return m(0,0)*(m(1,1)*m(2,2)-m(1,2)*m(2,1))-m(0,1)*(m(1,0)*m(2,2)-m(1,2)*m(2,0))+m(0,2)*(m(1,0)*m(2,1)-m(1,1)*m(2,0));
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

// TODO: recursive cofactor expansion to get determinant of any square matrix
template<typename T, int size>
T det(const Matrix<T,size,size> &m) {
  T total;
  for (int i = 0; i < size; i++) {
    if (i%2)
      total -= m(0,i)*minor(m,0,i);
    else
      total += m(0,i)*minor(m,0,i);
  }
  return total;
}

// cofactor matrix made by taking the deterimants of all minor matrices that compose the matrix 
// and multiping by a sign factor according to if the rows and or col is odd
inline matrix2 cof(const matrix2 &m) {
  return matrix2(
    minor(m,0,0), -minor(m,0,1),
    -minor(m,1,0), minor(m,1,1)
  );
}

inline matrix3 cof(const matrix3 &m) {
  return matrix3(
    minor(m,0,0), -minor(m,0,1), minor(m,0,2),
    -minor(m,1,0), minor(m,1,1), -minor(m,1,2),
    minor(m,2,0), -minor(m,2,1), minor(m,2,2)
  );
}

inline matrix4 cof(const matrix4 &m) {
  return matrix4(
    
  );
}

template <typename T, int size>
Matrix<T, size, size> cof(const Matrix<T, size, size> &m) {
  Matrix<T, size, size> result;
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      if ((i+j)%2)
        result(i,j) = -minor(m,i,j);
      else
        result(i,j) = minor(m,i,j);
    }
  }
  return result;
}

// What if I created a function that takes in a function pointer and performs opts on all the elements like this

// transpose of the cofactor matrix
template <typename T, int size>
Matrix<T, size, size> adjugate(const Matrix<T, size, size> &m) {
  Matrix<T,size,size> cofMatrix = cof(m);
  return transpose(cofMatrix);
}


inline matrix3 adjoint(const matrix3 &m) {
  return matrix3();
}

// TODO: add inverse functions
// NOTE: this function does not work probably at the moment, something is off with the cofactor matrix
// inline matrix3 inverse(const matrix3 &m) {
//   // taken from https://www.youtube.com/watch?v=srnaDoIKA-E 
//   matrix3 cofactor = cof(m);
//   cofactor = transpose(cofactor);
//   return (1/det(m))*cofactor;
// }

// inline Matrix4 inverse(const Matrix4 &m) {
//   Matrix4 cofactor = cof(m);
//   cofactor = transpose(cofactor);
//   return (1/det(m))*cofactor;
// }

// template<typename T, int size>
// Matrix<T,size,size> inverse(const Matrix<T,size,size> &m) {
//   Matrix<T,size,size> result;
//   result = (1/det(m))*adjugate(m);

//   return result;
// }

inline float3x3 inverse(const float3x3 &m) {
  // took this from glm
  float OneOverDeterminant = 1.0f / (
    +m[0][0] * (m[1][1] * m[2][2] - m[2][1] * m[1][2])
    - m[1][0] * (m[0][1] * m[2][2] - m[2][1] * m[0][2])
    + m[2][0] * (m[0][1] * m[1][2] - m[1][1] * m[0][2])
  );
      
  float3x3 inverse;
  inverse[0][0] = +(m[1][1] * m[2][2] - m[2][1] * m[1][2]);
  inverse[1][0] = -(m[1][0] * m[2][2] - m[2][0] * m[1][2]);
  inverse[2][0] = +(m[1][0] * m[2][1] - m[2][0] * m[1][1]);
  inverse[0][1] = -(m[0][1] * m[2][2] - m[2][1] * m[0][2]);
  inverse[1][1] = +(m[0][0] * m[2][2] - m[2][0] * m[0][2]);
  inverse[2][1] = -(m[0][0] * m[2][1] - m[2][0] * m[0][1]);
  inverse[0][2] = +(m[0][1] * m[1][2] - m[1][1] * m[0][2]);
  inverse[1][2] = -(m[0][0] * m[1][2] - m[1][0] * m[0][2]);
  inverse[2][2] = +(m[0][0] * m[1][1] - m[1][0] * m[0][1]);
  
  inverse *= OneOverDeterminant;
  return inverse;
}

inline float det(const float4x4 &m) {
  return 
    -m[2][0]*m[1][1]*m[0][2]+
    m[1][0]*m[2][1]*m[0][2]+
    m[2][0]*m[0][1]*m[1][2]-
    m[0][0]*m[2][1]*m[1][2]-
    m[1][0]*m[0][1]*m[2][2]+
    m[0][0]*m[1][1]*m[2][2];
} 

// TODO: assumes bottom row is 0,0,0,1
inline float4x4 inverse(const float4x4 &m) {
  float factor = 1.0f / det(m);

  float4 x;
  x.x = (-m[2][1]*m[1][2]+m[1][1]*m[2][2])*factor;
  x.y = (m[2][1]*m[1][2]-m[1][0]*m[2][2])*factor;
  x.z = (-m[2][1]*m[1][1]+m[1][0]*m[2][1])*factor;
  x.w = 0;

  float4 y;
  y.x = (m[2][1]*m[0][2]-m[0][1]*m[2][2])*factor;
  y.y = (-m[2][0]*m[0][2]+m[0][0]*m[2][2])*factor;
  y.z = (m[2][0]*m[0][1]-m[0][0]*m[2][1])*factor;
  y.w = 0;

  float4 z;
  z.x = (-m[1][1]*m[0][2]+m[0][1]*m[1][2])*factor;
  z.y = (m[1][0]*m[0][2]-m[0][0]*m[1][2])*factor;
  z.z = (-m[1][0]*m[0][1]+m[0][0]*m[1][1])*factor;
  z.w = 0;

  float4 w;
  w.x = (
    m[2][1]*m[1][2]*m[0][3] -
    m[1][1]*m[2][2]*m[0][3] -
    m[2][1]*m[0][2]*m[1][3] +
    m[0][1]*m[2][2]*m[1][3] +
    m[1][1]*m[0][2]*m[2][3] -
    m[0][1]*m[1][2]*m[2][3]
  ) * factor;
  w.y = (
    -m[2][0]*m[1][2]*m[0][3]
    +m[1][0]*m[2][2]*m[0][3]
    +m[2][0]*m[0][2]*m[1][3]
    -m[0][0]*m[2][2]*m[1][3]
    -m[1][0]*m[0][2]*m[2][3]
    +m[0][0]*m[1][2]*m[2][3]
  ) * factor;
  w.z = (
    m[2][0]*m[1][1]*m[0][3] -
    m[1][0]*m[2][1]*m[0][3] -
    m[2][0]*m[0][1]*m[1][3] +
    m[0][0]*m[2][1]*m[1][3] +
    m[1][0]*m[0][1]*m[2][3] -
    m[0][0]*m[1][1]*m[2][3]
  ) * factor;
  w.w = 1;

  return float4x4(
    x.x, y.x, z.x, w.x,
    x.y, y.y, z.y, w.y,
    x.z, y.z, z.z, w.z,
    x.w, y.w, z.w, w.w
  );
}

// TODO:
// B^-1MB
// B is the transformation of the object aka the transformation that takes the coords from world space ot local space
inline matrix4 changeBasis(const matrix4 &m, const matrix4 &b) {
  return matrix4(
    
  );
}

// TODO: Creates a rotation matrix from euler angles in the order of xyz
inline matrix3 rotationMatrix(float x, float y, float z) {
  return matrix3();
}

// TODO: optimize
template<typename T, int rows, int cols>
Vector<T,rows> getColumnVector(const Matrix<T, rows, cols> &m, int c) {
  Vector<T,rows> result;
  for (int i = 0; i < rows; i++) {
    result[i] = m(i,c);
  }
  return result;
}


template<typename T>
Matrix<T,4,4> perspectiveMatrix(T fovy, T aspect, T zNear, T zFar) {

  T const tanHalfFovy = tan(fovy / static_cast<T>(2));

  Matrix<T, 4, 4> Result;
  Result(0,0) = static_cast<T>(1) / (aspect * tanHalfFovy);
  Result(1,1) = static_cast<T>(1) / (tanHalfFovy);
  Result(2,2) = - (zFar + zNear) / (zFar - zNear);
  Result(3,2) = - static_cast<T>(1);
  Result(2,3) = - (static_cast<T>(2) * zFar * zNear) / (zFar - zNear);
  return Result;
}

template<typename T>
Matrix<T,4,4> translationMatrix(Vector<T,3> translation) {
  Matrix<T,4,4> matrix = Matrix<T,4,4>::identity();
  matrix(0,3) = translation.x;
  matrix(1,3) = translation.y;
  matrix(2,3) = translation.z;
  return matrix;
}



} // namespace bMath

#endif
