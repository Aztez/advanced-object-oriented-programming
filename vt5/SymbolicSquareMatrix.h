/**
 *\file SymbolicSquareMatrix.h
 *\brief Header for SymbolicSquareMatrix class
 */
#ifndef SYMBOLICSQUAREMATRIX_H_INCLUDE
#define SYMBOLICSQUAREMATRIX_H_INCLUDE
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "Element.h"
#include "VariableElement.h"
#include "IntElement.h"
#include "Valuation.h"
#include "ConcreteSquareMatrix.h"

/**
 * \class SymbolicSquareMatrix
 * \brief A class for square matrixes
 */
class SymbolicSquareMatrix{
public:
 /**
  * \brief Default constructor
  */
  SymbolicSquareMatrix();
 /**
  * \brief Parametric constructor
  * \param i11, i12, i21, i22 intelements for constructing square matrixes
  * \return intelements
  */
  SymbolicSquareMatrix(const std::string& strm);
 /**
  * \brief SymbolicSquareMatrix copy constructor
  * \param m Object to be copied
  * \return m type intelements
  */
  SymbolicSquareMatrix(const SymbolicSquareMatrix& m);
 /**
  * \brief SymbolicSquareMatrix copy constructor
  * \param m Object to be copied
  * \return m type intelements
  */  
  SymbolicSquareMatrix(SymbolicSquareMatrix&& m);
/**
  * \brief Default virtual SymbolicSquareMatrix destructor
  */
  virtual ~SymbolicSquareMatrix() = default;
/**
  * \brief Default copy constructor
  */  
  SymbolicSquareMatrix& operator= (const SymbolicSquareMatrix& m);
/**
  * \brief Default copy constructor
  */  
  SymbolicSquareMatrix& operator= (SymbolicSquareMatrix&& m);
/**
  * \brief Flips the SymbolicSquareMatrix around
  * \return SymbolicSquareMatrix
  */  
  SymbolicSquareMatrix transpose() const;
/**
  * \brief Copy constructor
  * \param another Help param for cpying
  * \return copy
  */
  bool operator == (const SymbolicSquareMatrix& m) const;
/**
  * \brief Saves to string
  * \return string
  */  
  std::string toString() const;
/**
  * \brief Prints string presentation of intelements
  * \param os Output stream
  * \return modified output stream
  */  
  void print(std::ostream& os) const;
/**
 * \brief Constructor for evaluations
 */      
  ConcreteSquareMatrix evaluate(const Valuation& v) const;
  
private:
  unsigned int n;
  std::vector<std::vector<std::unique_ptr<Element>>> elements;

};
/**
 * \brief Output operator for SymbolicSquareMatrix
 * \param os Output stream
 * \return modified output stream
 */
std::ostream& operator<<(std::ostream& os, const SymbolicSquareMatrix& m);

#endif //SYMBOLICSQUAREMATRIX_H_INCLUDED