/**
 * \file VariableElement.cpp 
 * \brief Source file for IntElement class
 */

#include "VariableElement.h"
#include "Element.h"

VariableElement::VariableElement() : VariableElement{'g'}{
}

VariableElement::VariableElement(char v){
  var = v;
}

char VariableElement::getVal() const{
  return var;
}

void VariableElement::setVal(char v){
  var = v;
}

bool VariableElement::operator == (const VariableElement& i) const {
  if(int(getVal() == i.getVal()))
    return true;
  else
    return false;
}

Element* VariableElement::clone() const {
  VariableElement* elem{new VariableElement{var}};
  return elem;    
}

std::string VariableElement::toString() const {
  std::stringstream ss;
  ss << var;
  return ss.str();
}

int VariableElement::evaluate(const Valuation& v) const{
  int val;
  
  try{
    val = v.at(var);
  }
  catch(const std::exception& e){
    throw std::invalid_argument{"Variable not valid"};
  }
  return val;
}

