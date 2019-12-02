/**
  * \file VariableElement.h 
  * \brief Header for IntElement class. Subclass of Element.h.
  */
#ifndef VARIABLEELEMENT_H_INCLUDE
#define VARIABLEELEMENT_H_INCLUDE
#include <iostream>
#include <sstream>
#include <memory>
#include <map>
#include "Element.h"

/**
  * \class VariableElement
  * \brief A class for encapsulating variables into matrix elements
  */
class VariableElement : public Element{  
public:
/**
  * \brief Constructor without param. Constructs VariableElement with var set to g.
  */
  VariableElement();
/**
  * \brief Constructor with param.
  * \param v -Variable for setting val 
  */
  VariableElement(char v);
/**
  * \brief Default virtual VariableElement deconstructor
  */
  virtual ~VariableElement() = default;
/**
  * \brief Constructor for getting value
  * \return char var -Value stored in the private var
  */  
  char getVal() const;
/**
  * \brief Constructor for setting value
  * \param v -Char for setting val
  */  
  void setVal(char v);
/**
  * \brief Abstract function for cloning element
  * \return Element* -pointer variable that points to new copy of the Element
  */     
  Element* clone() const override;
/**
  * \brief Abstract function for displaying VarElement as a string.
  * \return std::string -Element as a string
  */      
  std::string toString() const override;
/**
  * \brief Constructor for evaluations
  * \param Valuation& v -Stores values for the variables
  * \return int v -int value stored as int or char and valuated
  */   
  int evaluate(const Valuation& v) const override;

private:
/**
  * \brief Variable value held in class VariableElement
  */
  char var;
  
};

#endif //VARIABLEELEMENT_H_INCLUDED