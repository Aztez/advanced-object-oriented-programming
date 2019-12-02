/**
 * \file IntElement.cpp 
 * \brief Source file for IntElement class
 */

#include "IntElement.h"

IntElement::IntElement():IntElement(0){
}

IntElement::IntElement(int v):val(v){
}

int IntElement::getVal() const{
  return val;
}

void IntElement::setVal(int v){
  val = v;
}

IntElement& IntElement::operator+=(const IntElement& i){
  val += i.val;
  return *this;
}

IntElement& IntElement::operator-=(const IntElement& i){
  val -= i.val;
  return *this;
}

IntElement& IntElement::operator*=(const IntElement& i){
  val *= i.val;
  return *this;
}

bool IntElement::operator == (const IntElement& another) const {
  return val == another.val;
}

std::unique_ptr<IntElement> IntElement::clone() const {
  return std::unique_ptr<IntElement>(new IntElement(*this));      
}

IntElement operator+(const IntElement& i1, const IntElement& i2){
  IntElement result = i1;
  result += i2;
  return result;
}

IntElement operator-(const IntElement& i1, const IntElement& i2){
  IntElement result = i1;
  result -= i2;
  return result;
}

IntElement operator*(const IntElement& i1, const IntElement& i2){
  IntElement result = i1;
  result *= i2;
  return result;
} 

std::ostream& operator << (std::ostream& os, const IntElement& i){
  os << i.getVal();
  return os;
}
