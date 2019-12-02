/**
 * \file Element.h 
 * \brief Header for Element class
 */
#ifndef ELEMENT_H_INCLUDE
#define ELEMENT_H_INCLUDE
#include <iostream>
#include <sstream>
#include <memory>
#include "Valuation.h"

class Element{  
public:
/**
 * \brief Default virtual Element constructor
 */
  virtual ~Element() = default;
/**
 * \brief Constructor for cloning element
 */    
  virtual Element* clone() const = 0;
/**
 * \brief Constructor for saving to string
 */      
  virtual std::string toString() const = 0;
/**
 * \brief Constructor for evaluations
 */      
  virtual int evaluate(const Valuation& v) const = 0;
};
/**
 * \brief Output operator for Elements
 * \param os Output stream
 * \param i Element to be outputted
 * \return modified output stream
 */
std::ostream& operator << (std::ostream& os, const Element& i);

#endif //ELEMENT_H_INCLUDED
