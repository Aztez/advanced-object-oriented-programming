/**
  * \file CompositeElement.h 
  * \brief Header for CompositeElement class. Subclass of Element.h.
  */
#ifndef COMPOSITEELEMENT_H_INCLUDE
#define COMPOSITEELEMENT_H_INCLUDE
#include <iostream>
#include <sstream>
#include <memory>
#include <map>
#include "Element.h"

/**
  * \class CompositeElement
  * \brief A class for compositing elements into matrix elements
  */
class CompositeElement : public Element{  
public:
/**
  * \brief Default constructor
  */
  CompositeElement(const Element& e1, const Element& e2, const std::function<int(int,int)>& op, char opc);
/**
  * \brief Default constructor for compositeelements
  * \param CompositeElement& e -CompositeElement to be dublicated
  * \return CompositeElement& -New CompositeElement
  */
  CompositeElement(const CompositeElement& e);  
/** \brief = operator constructor for assigning CompositeElement to CompositeElement
  * \param CompositeElement& e -CompositeElement which is to be assigned
  * \return CompositeElement& -resulting CompositeElement
  */
  CompositeElement& operator=(const CompositeElement& e);
/**
  * \brief Default virtual CompositeElement deconstructor
  */
  virtual ~CompositeElement() = default;
/**
  * \brief Abstract function for cloning element
  * \return Element* -pointer variable that points to new copy of the Element
  */   
  Element* clone() const override;
/**
  * \brief Abstract function for displaying VarElement as a string.
  * \return std::string -element as a string
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
  * First Element of the CompositeElement
  */
  Element* opmd1;
/**
  * Second Element of the CompositeElement
  */
  Element* opmd2;
/**
  * Mathematical operator on CompositeElement
  */
  std::function<int(int,int)> op_fun;
/**
  * Operator cha character
  */  
  char op_ch;
  
};

#endif //COMPOSITEELEMENT_H_INCLUDED