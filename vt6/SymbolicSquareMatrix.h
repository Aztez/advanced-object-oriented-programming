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
 * \brief A class for square matrixes with intereg and char values
 */
class SymbolicSquareMatrix{
public:
/**
 * \brief Constructor without param. Constructs SymbolicSquareMatrix with size of 0.
 */
  SymbolicSquareMatrix();
/**
 * \brief Constructor which constructs a SymblicSquareMatrix with std::string as a specification
 * \param std::string& str -String according to which the SymbolicSquareMatrix will be constructed
 */
  SymbolicSquareMatrix(const std::string& strm);
/**
  * \brief SymbolicSquareMatrix copy constructor which duplicates another SymbolicSquareMatrix
  * \param m -Object to be copied
  */
  SymbolicSquareMatrix(const SymbolicSquareMatrix& m);
/**
  * \brief SymbolicSquareMatrix move constructor which takes another SymbolicSquareMatrix's values
  * \param m -temporary SymbolicSquareMatrix from which values are to be taken
  */  
  SymbolicSquareMatrix(SymbolicSquareMatrix&& m);
/**
  * \brief Default virtual SymbolicSquareMatrix destructor
  */
  virtual ~SymbolicSquareMatrix() = default;
/**
  * \brief =operator for assigning a SymbolicSquareMatrix over another symbolicSquareMatrix
  * \param SymbolicSquareMatrix& m -SymbolicSquareMatrix which is to be assigned
  * \return SymbolicSquareMatrix& -resulting SymbolicSquareMatrix
  */  
  SymbolicSquareMatrix& operator= (const SymbolicSquareMatrix& m);
/**
  * \brief =operator for assigning a temporary SymbolicSquareMatrix's values over another SymbolicSquareMatrix's
  * \param SymbolicSquareMatrix&& m -Temporary SymbolicSquareMatrix which values are to be used 
  * \return SymbolicSquareMatrix&& -resulting SymbolicSquareMatrix
  */  
  SymbolicSquareMatrix& operator= (SymbolicSquareMatrix&& m);
/**
  * \brief Function for transposing a SymbolicSquareMatrix
  * \return Transposed SymbolicSquareMatrix
  */
  SymbolicSquareMatrix transpose() const;
/**
 * \brief Addtions for SymbolicSquareMatrixs
 * \param m -Other matrix which helps adding numbers  
 * \return Calculated additions
 */  
  SymbolicSquareMatrix& operator+(const SymbolicSquareMatrix& m);
/**
 * \brief Subtractions for SymbolicSquareMatrixs
 * \param m -Other matrix which helps substracting numbers 
 * \return Calculated substractions
 */    
  SymbolicSquareMatrix& operator-(const SymbolicSquareMatrix& m);
/**
´* \brief Multipliciations for SymbolicSquareMatrixs
 * \param m -Other matrix which helps multiplicating numbers 
 * \return Calculated multiplications
 */   
  SymbolicSquareMatrix& operator*(const SymbolicSquareMatrix& m);  
/**
  * \brief == bool operator for comparing two matrixes
  * \param m -Second matrix for comparison
  * \return resulting symbolicsquarematrix
  */
  bool operator == (const SymbolicSquareMatrix& m) const;
/**
  * \brief Prints string presentation of matrix
  * \param os Output stream for output
  * \return modified output stream
  */  
  void print(std::ostream& os) const;
/**
  * \brief Saves matrix to string
  * \return string
  */  
  std::string toString() const;
/**
 * \brief Constructor for evaluations
 * \param Valuation& v stores values for the variables
 * \return int v -int value stored as int or char and valuated
 */      
  ConcreteSquareMatrix evaluate(const Valuation& v) const;
  
private:
/**
  * \brief The dimension length of the squarematrix
  */
  unsigned int n;
/**
  * \brief Two dimensional vector to hold the pointers to the elements
  */  
  std::vector<std::vector<std::unique_ptr<Element>>> elements;

};
/**
 * \brief Output operator for ConcreteSquareMatrix
 * \param os Output stream
 * \return modified output stream
 */
std::ostream& operator<<(std::ostream& os, const SymbolicSquareMatrix& m);

#endif //SYMBOLICSQUAREMATRIX_H_INCLUDED