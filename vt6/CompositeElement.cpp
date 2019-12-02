/**
 * \file CompositeElement.cpp 
 * \brief Source file for CompositeElement class
 */

#include "CompositeElement.h"
#include "Element.h"

CompositeElement::CompositeElement(const Element& e1, const Element& e2, const std::function<int(int,int)> op, char opc){

}

CompositeElement::CompositeElement(const CompositeElement& e){
  
}

CompositeElement& CompositeElement::operator = (const CompositeElement& e){

}

Element* CompositeElement::clone() const {
  CompositeElement* elem{new CompositeElement{*this}};
  return elem;    
}

std::string CompositeElement::toString() const {
  std::stringstream ss;
  ss << op_ch;
  return ss.str();
}

int CompositeElement::evaluate(const Valuation& v) const{
  int val;
  
  try{
    val = v.at(op_ch);
  }
  catch(const std::exception& e){
    throw std::invalid_argument{"Variable not valid"};
  }
  return val;
}

