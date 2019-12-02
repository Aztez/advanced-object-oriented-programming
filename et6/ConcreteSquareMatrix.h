/**
  *\file ConcreteSquareMatrix.h
  *\brief Header for ConcreteSquareMatrix class
  */
#ifndef CONCRETESQUAREMATRIX_H_INCLUDE
#define CONCRETESQUAREMATRIX_H_INCLUDE
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "IntElement.h"
#include "VariableElement.h"
#include "Element.h"
/**
  * \class ConcreteSquareMatrix
  * \brief A class for square matrixes with integer values
  */
class ConcreteSquareMatrix{
public:
/**
  * \brief Constructor without param. Constructs ConcreteSquareMatrix with size of 0.
  */
  ConcreteSquareMatrix();
/**
  * \brief Constructor which constructs a ConcreteSquareMatrix with std::string as a specification
  * \param std::string& str -String according to which the ConcreteSquareMatrix will be constructed
  */
  ConcreteSquareMatrix(const std::string& strm);
/**
  * \brief ConcreteSquareMatrix copy constructor which duplicates another ConcreteSquareMatrix
  * \param m -Object to be copied
  */
  ConcreteSquareMatrix(const ConcreteSquareMatrix& m);
/**
  * \brief ConcreteSquareMatrix move constructor which takes another ConcreteSquareMatrix's values
  * \param m -temporary ConcreteSquareMatrix from which values are to be taken
  */  
  ConcreteSquareMatrix(ConcreteSquareMatrix&& m);
/**
  * \brief Default virtual ConcreteSquareMatrix destructor
  */
  virtual ~ConcreteSquareMatrix() = default;
/**
  * \brief =operator for assigning a ConcreteSquareMatrix over another ConcreteSquareMatrix
  * \param ConcreteSquareMatrix& m -ConcreteSquareMatrix which is to be assigned
  * \return ConcreteSquareMatrix& -resulting ConcreteSquareMatrix
  */  
  ConcreteSquareMatrix& operator= (const ConcreteSquareMatrix& m);
/**
  * \brief =operator for assigning a temporary ConcreteSquareMatrix's values over another ConcreteSquareMatrix's
  * \param ConcreteSquareMatrix&& m -Temporary ConcreteSquareMatrix which values are to be used 
  * \return ConcreteSquareMatrix& -resulting ConcreteSquareMatrix
  */  
  ConcreteSquareMatrix& operator= (ConcreteSquareMatrix&& m);
/**
  * \brief Function for transposing a ConcreteSquareMatrix
  * \return Transposed ConcreteSquareMatrix
  */
  ConcreteSquareMatrix transpose() const;
/**
  * \brief Addtions for square matrixes
  * \param m -Other matrix which helps adding numbers  
  * \return Calculated additions
  */
  ConcreteSquareMatrix& operator += (const ConcreteSquareMatrix& m);
/**
  * \brief Subtractions for square matrixes
  * \param m -Other matrix which helps substracting numbers 
  * \return Calculated substractions
  */  
  ConcreteSquareMatrix& operator -= (const ConcreteSquareMatrix& m);
/**
  * \brief Multipliciations for square matrixes
  * \param m -Other matrix which helps multiplicating numbers 
  * \return Calculated multiplications
  */  
  ConcreteSquareMatrix& operator *= (const ConcreteSquareMatrix& m);
/**
  * \brief == bool operator for comparing two matrixes
  * \param m -Second matrix for comparison
  * \return resulting concretesquarematrix
  */
  bool operator == (const ConcreteSquareMatrix& m) const;
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

private:
/**
  * \brief The dimension length of the squarematrix
  */
  unsigned int n;
/**
  * \brief Two dimensional vector to hold the pointers to the IntElements
  */  
  std::vector<std::vector<std::unique_ptr<IntElement>>> elements;

};

#endif //ConcreteSquareMatrix_H_INCLUDED