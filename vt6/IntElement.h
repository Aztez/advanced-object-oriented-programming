/**
  * \file IntElement.h 
  * \brief Header for IntElement class. Subclass of Element.h
  */
#ifndef INTELEMENT_H_INCLUDE
#define INTELEMENT_H_INCLUDE
#include <iostream>
#include <sstream>
#include <memory>
#include <map>
#include "Element.h"

/**
  * \class IntElement
  * \brief A class for encapsulating integers into matrix elements
  */

class IntElement : public Element{  
public:
/**
  * \brief Constructor without param. Constructs IntElement with val set to 0.
  */
  IntElement();
/**
  * \brief Constructor with param.
  * \param v Integer for setting val 
  */
  IntElement(int v);
/**
  * \brief Default virtual IntElement deconstructor
  */
  virtual ~IntElement() = default;
/**
  * \brief Constructor for getting value
  * \return int val -Value stored in the private int
  */  
  int getVal() const;
/**
  * \brief Constructor for setting value
  * \param v -Integer for setting val
  */  
  void setVal(int v);
/**
  * \brief Abstract function for cloning element
  * \return Element* -pointer variable that points to new copy of the Element
  */    
  Element* clone() const override;
/**
  * \brief Abstract function for displaying IntElement as a string.
  * \return std::string -element as a string
  */      
  std::string toString() const override;
/**
  * \brief Constructor for evaluations
  * \param Valuation& v -Stores values for the variables
  * \return int v -int value stored as int or char and valuated
  */      
  int evaluate(const Valuation& v) const override;
/**
  * \brief Addtions for intelements
  * \param i -Other int which helps adding numbers 
  * \return Calculated additions
  */  
  IntElement& operator += (const IntElement& i);
/**
  * \brief Subtractions for intelements
  * \param i -Other int which helps subtracting numbers 
  * \return Calculated substractions
  */    
  IntElement& operator -= (const IntElement& i);
/**
´ * \brief Multipliciations for intelements
  * \param i -Other int which helps multiplying numbers 
  * \return Calculated multiplications
  */   
  IntElement& operator *= (const IntElement& i);
 
private:
/**
  * \brief Integer value held in class IntElement
  */
  int val;
  
};
/**
 * \brief Addtions for intelements
 * \param i1, 12 Helps adding numbers 
 * \return Calculated additions
 */  
IntElement operator + (const IntElement& i1, const IntElement& i2);
/**
 * \brief Subtractions for intelements
 * \param i1, i2 Helps subtracting numbers 
 * \return Calculated substractions
 */ 
IntElement operator - (const IntElement& i1, const IntElement& i2);
/**
´* \brief Multipliciations for intelements
 * \param i1, i2 Helps multiplying numbers 
 * \return Calculated multiplications
 */
IntElement operator * (const IntElement& i1, const IntElement& i2);

#endif //INTELEMENT_H_INCLUDED