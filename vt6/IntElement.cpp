/**
 * \file IntElement.cpp 
 * \brief Source file for IntElement class
 */

#include "IntElement.h"

IntElement::IntElement() : IntElement{0}{
}

IntElement::IntElement(int v) : val{v}{
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

Element* IntElement::clone() const {
  IntElement* elem{new IntElement{val}};
  return elem;
}

std::string IntElement::toString() const {
  std::stringstream ss;
  ss << val;
  return ss.str();
}

int IntElement::evaluate(const Valuation& v) const{
  return val;
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
