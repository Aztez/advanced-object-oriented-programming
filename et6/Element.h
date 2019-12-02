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
  * \brief Default virtual Element deconstructor
  */
  virtual ~Element() = default;
/**
  * \brief Abstract function for cloning element
  * \return Element* -pointer variable that points to new copy of the Element
  */    
  virtual Element* clone() const = 0;
/**
  * \brief Abstract function for displaying Element as a string.
  * \return std::string -element as a string
  */      
  virtual std::string toString() const = 0;
/**
  * \brief Constructor for evaluations
  * \param Valuation& v stores values for the variables
  * \return int v -int value stored as int or char and valuated
  */      
  virtual int evaluate(const Valuation& v) const = 0;
};

#endif //ELEMENT_H_INCLUDED
