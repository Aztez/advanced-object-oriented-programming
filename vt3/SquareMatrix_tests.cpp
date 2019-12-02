/**
 * \file SquareMatrix_tests.cpp
 * \brief Tests for square matrixes
 */
#define CATCH_CONFIG_MAIN
#include <stdexcept>
#include "catch.hpp"
#include "SquareMatrix.h"
/**
 * \brief Basic test cases for square matrixes
 */
TEST_CASE("Basic matrix computations", "[matrix]"){
    CHECK_NOTHROW(SquareMatrix("[[1]]"));
    CHECK_NOTHROW(SquareMatrix("[[1,2][1,2]]"));
    CHECK_NOTHROW(SquareMatrix("[[1,2,3][4,5,6][1,2,3]]"));
    CHECK_NOTHROW(SquareMatrix("[[1,2,3,4][4,5,6,4][1,2,3,4][6,5,3,2]]"));
    CHECK_THROWS(SquareMatrix("["));
    CHECK_THROWS(SquareMatrix("[["));
    CHECK_THROWS(SquareMatrix("]"));
    CHECK_THROWS(SquareMatrix("]]"));
    CHECK_THROWS(SquareMatrix("[[1,]"));
    CHECK_THROWS(SquareMatrix("[[1,2][1,2,2]]"));
    CHECK_THROWS(SquareMatrix("[[1,2,4][1,2,2"));
    CHECK_THROWS(SquareMatrix("[[1,2,4]]"));
    CHECK_THROWS(SquareMatrix("[[1,2]]xxx"));
    CHECK_THROWS(SquareMatrix("[[1,[1,2]]"));
    CHECK_THROWS(SquareMatrix("[[1,2][asd]]"));
    CHECK_THROWS(SquareMatrix("adsa[[1]]"));
    CHECK_THROWS(SquareMatrix("[[1,2]asa[1,2]]"));
    CHECK_THROWS(SquareMatrix("[[.,a][a,v]]"));
    CHECK_THROWS(SquareMatrix("[[1][[1]"));
    CHECK_THROWS(SquareMatrix("[[1][[]]"));
}

/**
 * \brief Various test cases for testing calculations
 */
TEST_CASE("Square matrix calculations" "[SquareMatrix]"){

/**
 * \brief Testing basic functionality of toString and print
 */    
  SquareMatrix sqm1{"[[1,1][1,1]]"}; 
  CHECK(sqm1.toString()=="[[1,1][1,1]]");
  std::cout << sqm1 << std::endl;
  
/**
 * \brief Testing basic functionality of == function
 */    
  SquareMatrix sqm2{"[[1,1][1,2]]"}; 
  CHECK_FALSE(sqm2 == SquareMatrix{"[[1,1][1,1]]"});
  SquareMatrix sqm4{"[[1,1][1,1]]"}; 
  CHECK(sqm4 == SquareMatrix{"[[1,1][1,1]]"});    
  
/**
 * \brief Minus calculations
 */
  SquareMatrix minus1{"[[6,44][2,9]]"};
  SquareMatrix minus2{"[[2,3][4,5]]"};
  minus1 = minus1 - minus2;
  CHECK(minus1.toString()=="[[4,41][-2,4]]");    

/**
 * \brief Plus calculations
 */
  SquareMatrix plus1{"[[5,7][21,1]]"};
  SquareMatrix plus2{"[[2,3][8,54]]"};
  plus1 = plus1 + plus2;
  CHECK(plus1.toString()=="[[7,10][29,55]]");    
  
/**
 * \brief Times calculations
 */
  SquareMatrix times1{"[[2,1][5,7]]"};
  SquareMatrix times2{"[[2,3][4,5]]"};
  times1 = times1 * times2;
  CHECK(times1.toString()=="[[8,11][38,50]]");
  
/**
 * \brief Transpose test
 */
  SquareMatrix trnsps1{"[[1,2][3,4]]"}; 
  SquareMatrix trnsps2 = trnsps1.transpose();
  CHECK(trnsps1.toString() == "[[1,2][3,4]]");
  CHECK(trnsps2.toString() == "[[1,3][2,4]]");
  
/**
 * \brief Test for empty and throws
 */
  SquareMatrix empty{};
  SquareMatrix empty2{empty};
  CHECK(empty.toString() == empty2.toString());
  CHECK_THROWS(empty += SquareMatrix{"[[1,1][1,1]]"});

/**
 * \brief Test for strringstream
 */  
    std::stringstream ss{};
    ss << SquareMatrix{"[[2,2][2,2]]"};
    CHECK (ss.str() == "[[2,2][2,2]]");

}
