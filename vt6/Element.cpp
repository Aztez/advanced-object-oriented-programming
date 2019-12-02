/**
 * \file Element.cpp 
 * \brief Source file for Element class
 */

#include "Element.h"

std::ostream& operator << (std::ostream& os, const Element& i){
  os << i.toString();
  return os;
}

bool operator== (const Element& i, const Element& i2){
  if(i == i2)
    return true;
    
  else
    return false;
}


bool Element::operator== (const Element& i){ return true; }