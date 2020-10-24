#include <gtest/gtest.h>

#include <iostream>
#include <vector>

#include "linalg/vector.h"

class VectorTest : public ::testing::Test {
public:
    typedef linalg::Vector Vector;

};

TEST_F(VectorTest, vector_instantiation) {
    Vector a(3);
    a(1) = 3;
    EXPECT_EQ(0, a(2));
    EXPECT_EQ(3, a(1));
}

// TEST_F(VectorTest, vector_access) {
//     Vector vector(3);
//     vector.set(2, 4);
//     vector(1) = 2;
//     EXPECT_EQ(2, vector(1));
//     EXPECT_EQ(4, vector(2));
// }
// 
// TEST_F(VectorTest, vector_print) {
//     Vector vector(10);
//     for(int i = 0; i < vector.size(); i++) {
//       vector(i) = i;
//     }
//     vector.print();
//     EXPECT_EQ(0, 0);
// }
// 
// TEST_F(VectorTest, vector_add) {
//     Vector a(10);
//     Vector b(10);
//     Vector c(10);
//     for(int i = 0; i < a.size(); i++) {
//       a(i) = i;
//     }
//     for(int i = 0; i < b.size(); i++) {
//       b(i) = 10 - i;
//     }
//     c = a.add(b);
//     EXPECT_EQ(c(3), 10);
//     c = a + b;
//     EXPECT_EQ(c(3), 10);
// }
// 
// 
// TEST_F(VectorTest, vector_subtract) {
//     Vector a(10);
//     Vector b(10);
//     Vector c(10);
//     for(int i = 0; i < a.size(); i++) {
//       a(i) = i;
//     }
//     for(int i = 0; i < b.size(); i++) {
//       b(i) = 10 - i;
//     }
//     c = a.subtract(b);
//     EXPECT_EQ(c(3), -4);
//     c = a - b;
//     EXPECT_EQ(c(3), -4);
// }
// 
// TEST_F(VectorTest, elementwise_prod) {
//     Vector a(10);
//     Vector b(10);
//     Vector c(10);
//     for(int i = 0; i < a.size(); i++) {
//       a(i) = i;
//     }
//     for(int i = 0; i < b.size(); i++) {
//       b(i) = 10 - i;
//     }
//     c = a.elementwise_prod(b);
//     EXPECT_EQ(c(3), 21);
// }
// 
// 
// TEST_F(VectorTest, dot_prod) {
//     Vector a(10);
//     Vector b(10);
//     Vector c(10);
//     for(int i = 0; i < a.size(); i++) {
//       a(i) = i;
//     }
//     for(int i = 0; i < b.size(); i++) {
//       b(i) = 10 - i;
//     }
//     c = a.dot_prod(b);
//     EXPECT_EQ(c(3), 3);
// }
