/**
 * \file SquareMatrix_tests.cpp
 * \brief Tests for square matrixes
 */
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "SquareMatrix.h"
/**
 * \brief Various test cases for square matrixes
 */
TEST_CASE("Square matrix calculations" "(SquareMatrix)"){
  IntElement x11(3),x12(-5),x21(7),x22(9);
  IntElement y11(2),y12(1),y21(2),y22(3);
  SquareMatrix sqm1(x11, x12, x21, x22);
  SquareMatrix sqm2(y11, y12, y21, y22);
  SquareMatrix sqm3(sqm2);
  SquareMatrix mqs();
  
  CHECK(sqm1.toString()=="[[3,-5][7,9]]");
  
  sqm1 += sqm2;
  CHECK(sqm1.toString()=="[[5,-4][9,12]]");
  sqm1 -= sqm2;
  CHECK(sqm1.toString()=="[[3,-5][7,9]]");
  sqm1 *= sqm2;
  CHECK(sqm1.toString()=="[[-4,-12][32,34]]");
  
  sqm3.print(std::cout);
  CHECK(sqm3.toString()==sqm2.toString());
}
