/**
 * \file Tests.cpp
 * \brief Tests for square matrixes
 */
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "Valuation.h"
#include "ConcreteSquareMatrix.h"
#include "SymbolicSquareMatrix.h"
#include "Element.h"
#include "VariableElement.h"
#include "IntElement.h"
/**
 * \brief Various test cases for intelements
 */
TEST_CASE("IntElement testing", "[IntElement]"){
  IntElement ie2(5);
  ie2.setVal(5);
  CHECK(ie2.getVal()==5); 
  IntElement ie(7);
  REQUIRE(ie.getVal()==7);
  IntElement ie_plus(-15);
  ie += ie_plus;
  CHECK(ie.getVal()==-8);
  IntElement ie_minus(5);
  ie -= ie_minus;
  CHECK(ie.getVal()==-13);
  IntElement ie_times(2);
  ie *= ie_times;
  CHECK(ie.getVal()==-26);
  IntElement ie_sum = ie + ie_plus;
  CHECK(ie_sum.getVal()==-41);
  IntElement ie_minuss = ie - ie_plus;
  CHECK(ie_minuss.getVal()==-11);
  IntElement ie_timess = ie * ie_plus;
  CHECK(ie_timess.getVal()==390);
  std::cout << ie << std::endl;
  std::cout << ie_timess << std::endl;
  IntElement ie0{};
  CHECK(ie0.getVal()==0);
  
}

/**
 * \brief Various test cases for intelements
 */
TEST_CASE("VariableElement testing", "[variableelement]"){
  VariableElement ve1{'a'};
  ve1.setVal('a');
  CHECK(ve1.getVal()=='a'); 
  VariableElement ve2{'B'};
  REQUIRE(ve2.getVal()=='B');
  std::cout << ve1 << std::endl;
  VariableElement ve0{};
  ve0.setVal('x');
  CHECK(ve0.getVal()=='x');
  VariableElement veCopy(ve0);
  CHECK(veCopy.toString() == "x");
  CHECK(veCopy.getVal() == 'x');
  VariableElement veCopy2(std::move(veCopy));
  CHECK(veCopy2.toString() == "x");
  CHECK(veCopy2.getVal() == 'x');
  CHECK(ve0 == veCopy2);
  
  Valuation val;
  val.insert(std::pair<char,int>('x',10));
  val.insert(std::pair<char,int>('y',50));
  val.insert(std::pair<char,int>('z',300));
  
  CHECK(ve0.evaluate(val) == veCopy2.evaluate(val));
  veCopy2.setVal('y');
  CHECK(veCopy2.evaluate(val) == 50);
  CHECK_FALSE(veCopy2.evaluate(val) == 10);
  std::cout << veCopy2 << std::endl;
  
  VariableElement veFail('b');
  CHECK_THROWS(veFail.evaluate(val));
  std::cout << veFail << std::endl;
  
}

/**
 * \brief Basic test cases for square matrixes
 */
TEST_CASE("Basic matrix computations", "[concretesquarematrix]"){
    CHECK_NOTHROW(ConcreteSquareMatrix("[[1]]"));
    CHECK_NOTHROW(ConcreteSquareMatrix("[[1,2][1,2]]"));
    CHECK_NOTHROW(ConcreteSquareMatrix("[[1,2,3][4,5,6][1,2,3]]"));
    CHECK_NOTHROW(ConcreteSquareMatrix("[[1,2,3,4][4,5,6,4][1,2,3,4][6,5,3,2]]"));
    CHECK_THROWS(ConcreteSquareMatrix("["));
    CHECK_THROWS(ConcreteSquareMatrix("[["));
    CHECK_THROWS(ConcreteSquareMatrix("]"));
    CHECK_THROWS(ConcreteSquareMatrix("]]"));
    CHECK_THROWS(ConcreteSquareMatrix("[[1,]"));
    CHECK_THROWS(ConcreteSquareMatrix("[[1,2][1,2,2]]"));
    CHECK_THROWS(ConcreteSquareMatrix("[[1,2,4][1,2,2"));
    CHECK_THROWS(ConcreteSquareMatrix("[[1,2,4]]"));
    CHECK_THROWS(ConcreteSquareMatrix("[[1,2]]xxx"));
    CHECK_THROWS(ConcreteSquareMatrix("[[1,[1,2]]"));
    CHECK_THROWS(ConcreteSquareMatrix("[[1,2][asd]]"));
    CHECK_THROWS(ConcreteSquareMatrix("adsa[[1]]"));
    CHECK_THROWS(ConcreteSquareMatrix("[[1,2]asa[1,2]]"));
    CHECK_THROWS(ConcreteSquareMatrix("[[.,a][a,v]]"));
    CHECK_THROWS(ConcreteSquareMatrix("[[1][[1]"));
    CHECK_THROWS(ConcreteSquareMatrix("[[1][[]]"));
}


/**
 * \brief Basic test cases for square matrixes
 */
TEST_CASE("Basic symbolicmatrix computations", "[symbolicsquarematrix]"){
    CHECK_NOTHROW(SymbolicSquareMatrix("[[]]"));
    CHECK_NOTHROW(SymbolicSquareMatrix("[[x,y][z,Y]]"));
    CHECK_NOTHROW(SymbolicSquareMatrix("[[a,b,c][d,e,g][A,s,E]]"));
    CHECK_NOTHROW(SymbolicSquareMatrix("[[1,A,R,4][W,5,w,4][c,2,3,4][x,q,D,2]]"));
    CHECK_THROWS(SymbolicSquareMatrix("["));
    CHECK_THROWS(SymbolicSquareMatrix("[["));
    CHECK_THROWS(SymbolicSquareMatrix("]"));
    CHECK_THROWS(SymbolicSquareMatrix("]]"));
    CHECK_THROWS(SymbolicSquareMatrix("[[1,]"));
    CHECK_THROWS(SymbolicSquareMatrix("[[1,2][1,2,2]]"));
    CHECK_THROWS(SymbolicSquareMatrix("[[1,2,4][1,2,2"));
    CHECK_THROWS(SymbolicSquareMatrix("[[1,2,4]]"));
    CHECK_THROWS(SymbolicSquareMatrix("[[1,2]]xxx"));
    CHECK_THROWS(SymbolicSquareMatrix("[[1,[1,2]]"));
    CHECK_THROWS(SymbolicSquareMatrix("[[1,2][asd]]"));
    CHECK_THROWS(SymbolicSquareMatrix("adsa[[1]]"));
    CHECK_THROWS(SymbolicSquareMatrix("[[1,2]asa[1,2]]"));
    CHECK_THROWS(SymbolicSquareMatrix("[[.,a][a,v]]"));
    CHECK_THROWS(SymbolicSquareMatrix("[[1][[1]"));
    CHECK_THROWS(SymbolicSquareMatrix("[[1][[]]"));
}

/**
 * \brief Various test cases for testing calculations
 */
TEST_CASE("Square matrix calculations" "[matrix]"){

/**
 * \brief Testing basic functionality of toString and print
 */    
  ConcreteSquareMatrix sqm1{"[[1,1][1,1]]"}; 
  CHECK(sqm1.toString()=="[[1,1][1,1]]");
  std::cout << sqm1 << std::endl;
  
/**
 * \brief Testing basic functionality of == function
 */    
  ConcreteSquareMatrix sqm2{"[[1,1][1,2]]"}; 
  CHECK_FALSE(sqm2 == ConcreteSquareMatrix{"[[1,1][1,1]]"});
  ConcreteSquareMatrix sqm4{"[[1,1][1,1]]"}; 
  CHECK(sqm4 == ConcreteSquareMatrix{"[[1,1][1,1]]"});    
  
/**
 * \brief Minus calculations
 */
  ConcreteSquareMatrix minus1{"[[6,44][2,9]]"};
  ConcreteSquareMatrix minus2{"[[2,3][4,5]]"};
  minus1 = minus1 - minus2;
  CHECK(minus1.toString()=="[[4,41][-2,4]]");    

/**
 * \brief Plus calculations
 */
  ConcreteSquareMatrix plus1{"[[5,7][21,1]]"};
  ConcreteSquareMatrix plus2{"[[2,3][8,54]]"};
  plus1 = plus1 + plus2;
  CHECK(plus1.toString()=="[[7,10][29,55]]");    
  
/**
 * \brief Times calculations
 */
  ConcreteSquareMatrix times1{"[[2,1][5,7]]"};
  ConcreteSquareMatrix times2{"[[2,3][4,5]]"};
  times1 = times1 * times2;
  CHECK(times1.toString()=="[[8,11][38,50]]");
  
/**
 * \brief Transpose test
 */
  ConcreteSquareMatrix trnsps1{"[[1,2][3,4]]"}; 
  ConcreteSquareMatrix trnsps2 = trnsps1.transpose();
  CHECK(trnsps1.toString() == "[[1,2][3,4]]");
  CHECK(trnsps2.toString() == "[[1,3][2,4]]");
  
/**
 * \brief Test for empty and throws
 */
  ConcreteSquareMatrix empty{};
  ConcreteSquareMatrix empty2{empty};
  CHECK(empty.toString() == empty2.toString());
  CHECK_THROWS(empty += ConcreteSquareMatrix{"[[1,1][1,1]]"});

/**
 * \brief Test for stringstream
 */  
    std::stringstream ss{};
    ss << ConcreteSquareMatrix{"[[2,2][2,2]]"};
    CHECK (ss.str() == "[[2,2][2,2]]");

}
