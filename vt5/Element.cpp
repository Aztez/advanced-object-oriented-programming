/**
 * \file Element.cpp 
 * \brief Source file for Element class
 */

#include "Element.h"

std::ostream& operator << (std::ostream& os, const Element& i){
  os << i.toString();
  return os;
}
