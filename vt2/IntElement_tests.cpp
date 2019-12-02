/**
 * \file IntElement_tests.cpp 
 * \brief Tests for intelements
 */
#include "catch.hpp"
#include "IntElement.h"
#include <iostream>
/**
 * \brief Various test cases for intelements
 */
TEST_CASE("IntElement testing", "(IntElement)"){
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
  IntElement ie0{};
  CHECK(ie0.getVal()==0);

}
