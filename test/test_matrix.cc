#include <gtest/gtest.h>

#include <iostream>
#include <vector>

#include "linalg/matrix.h"

class MatrixTest : public ::testing::Test {
public:
    typedef linalg::Matrix Matrix;

};

TEST_F(MatrixTest, matrix_instantiation) {
    Matrix matrix(2, 3);
    EXPECT_EQ(0, matrix(1,1));
}

TEST_F(MatrixTest, matrix_assignment) {
    Matrix matrix(2, 3);
    matrix(1, 1) = 42;
    EXPECT_EQ(42, matrix(1,1));
}

TEST_F(MatrixTest, matrix_show) {
    Matrix a(2, 3);
    for(int i = 0; i < a.m; i++) {
      for(int j = 0; j < a.n; j++) {
	a(i,j) = i + j;
      }
    }
    matrix_show(a);
    EXPECT_EQ(0, 0);
}
//
TEST_F(MatrixTest, matrix_multiplication) {
    Matrix a(2, 3);
    Matrix b(3, 2);
    for(int i = 0; i < a.m; i++) {
      for(int j = 0; j < a.n; j++) {
    	a(i,j) = i + j;
      }
    }
    for(int i = 0; i < b.m; i++) {
      for(int j = 0; j < b.n; j++) {
    	b(i,j) = i - j;
      }
    }
    Matrix c(2, 2);
    c.mult(a, b);
    // matrix_show(c);
    c = a * b;
    // matrix_show(c);
  // TODO: set meaningful expectation here
    EXPECT_EQ(1, 1); // TODO: Check this answer
}



TEST_F(MatrixTest, matrix_qr) {
  double in[][3] = {
    { 12, -51,   4},
    {  6, 167, -68},
    { -4,  24, -41},
  };

  Matrix A(in);
  Matrix Q, R;

  matrix_show(A,"A");

  // compute QR decompostion
  householder(A, R, Q);

  // matrix_show(Q,"Q");
  // matrix_show(R,"R");

  // compare Q*R to the original matrix A
  Matrix A_check;
  A_check.mult(Q, R);

  // compute L2 norm ||A-A_check||^2
  double l2 = matrix_compare(A,A_check);

  // display Q*R
  // matrix_show(A_check, l2 < 1e-12 ? "A == Q * R ? yes" : "A == Q * R ? no");

  // TODO: set meaningful expectation here
  EXPECT_EQ(1, 1); // TODO: Check this answer
}


TEST_F(MatrixTest, matrix_mult_bin) {
    Matrix a(2, 3);
    Matrix b(3, 2);
    for(int i = 0; i < a.n; i++) {
      for(int j = 0; j < a.m; j++) {
	a(i,j) = i + j;
      }
    }
    for(int i = 0; i < a.n; i++) {
      for(int j = 0; j < a.m; j++) {
	b(i,j) = i - j;
      }
    }
    Matrix c(2, 2);
    c = a * b;
    // TODO: Check if this equality holds
    EXPECT_EQ(c(0,0), 8);
}

TEST_F(MatrixTest, matrix_transpose) {
    Matrix a(2, 3);
    std::cout << a.n << "\n\n";
    Matrix c(3, 2);
    for(int i = 0; i < a.m; i++) {
      for(int j = 0; j < a.n; j++) {
	a(i,j) = i + j;
      }
    }
    matrix_show(a);
    a = a.tcopy();
    // matrix_show(a);
    EXPECT_EQ(a(0,0), 0);
    EXPECT_EQ(c(0,0), 0);
}


TEST_F(MatrixTest, matrix_lsqr) {
  double inx[][11] = {
    {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10}
  };
  double iny[][11] = {
    {1, 6, 17, 34, 57, 86, 121, 162, 209, 262, 321}
  };

  Matrix x(inx);
  Matrix y(iny);
  Matrix beta;
//  beta = polyfit(x, y, 2);

//  matrix_show(beta,"beta");


  EXPECT_EQ(1, 1); // TODO: Check this answer
}
