/**
 * \file VariableElement.h 
 * \brief Header for IntElement class
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
 * \brief A class for encapsulating integers into matrix elements
 */
class VariableElement : public Element{  
public:
/**
 * \brief Default constructor
 */
  VariableElement();
/**
 * \brief Default virtual VariableElement constructor
 */
  virtual ~VariableElement() = default;
/**
 * \brief VariableElement constructor
 * \param v Integer for setting val 
 */
  VariableElement(char v);
/**
 * \brief Constructor for getting value
 */  
  char getVal() const;
/**
 * \brief Constructor for setting value
 * \param v Char for setting val
 */  
  void setVal(char v);
/**
 * \brief Constructor for checking element
 */     
  bool operator == (const VariableElement& i) const;
/**
 * \brief Constructor for cloning element
 */       
  Element* clone() const override;
  /**
 * \brief Constructor for saving to string
 */       
  std::string toString() const override;
/**
 * \brief Constructor for evaluations
 */    
  int evaluate(const Valuation& v) const override;

private:
  char var;
};

#endif //VARIABLEELEMENT_H_INCLUDED