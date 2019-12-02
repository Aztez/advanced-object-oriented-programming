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
 * \brief A class for square matrixes
 */
class ConcreteSquareMatrix{
public:
 /**
  * \brief Default constructor
  */
  ConcreteSquareMatrix();
 /**
  * \brief Parametric constructor
  * \param i11, i12, i21, i22 intelements for constructing square matrixes
  * \return intelements
  */
  ConcreteSquareMatrix(const std::string& strm);
 /**
  * \brief Constructor for concretesquarematrix class
  */
  ConcreteSquareMatrix(std::vector<std::vector<std::unique_ptr<IntElement>>> v);
 /**
  * \brief ConcreteSquareMatrix copy constructor
  * \param m Object to be copied
  * \return m type intelements
  */
  ConcreteSquareMatrix(const ConcreteSquareMatrix& m);
 /**
  * \brief ConcreteSquareMatrix copy constructor
  * \param m Object to be copied
  * \return m type intelements
  */  
  ConcreteSquareMatrix(ConcreteSquareMatrix&& m);
/**
  * \brief Default virtual ConcreteSquareMatrix destructor
  */
  virtual ~ConcreteSquareMatrix() = default;
/**
  * \brief Default copy constructor
  */  
  ConcreteSquareMatrix& operator= (const ConcreteSquareMatrix& m);
/**
  * \brief Default copy constructor
  */  
  ConcreteSquareMatrix& operator= (ConcreteSquareMatrix&& m);
/**
  * \brief Flips the ConcreteSquareMatrix around
  * \return ConcreteSquareMatrix
  */  
  ConcreteSquareMatrix transpose() const;
/**
  * \brief Addtions for square matrixes
  * \param m Helps adding numbers 
  * \return Calculated additions
  */
  ConcreteSquareMatrix& operator += (const ConcreteSquareMatrix& m);
/**
  * \brief Subtractions for square matrixes
  * \param m Helps subtracting numbers 
  * \return Calculated substractions
  */  
  ConcreteSquareMatrix& operator -= (const ConcreteSquareMatrix& m);
/**
  * \brief Multipliciations for square matrixes
  * \param m Helps multiplying numbers 
  * \return Calculated multiplications
  */  
  ConcreteSquareMatrix& operator *= (const ConcreteSquareMatrix& m);
/**
  * \brief Copy constructor
  * \param another Help param for cpying
  * \return copy
  */
  bool operator == (const ConcreteSquareMatrix& m) const;
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

private:
  unsigned int n;
  std::vector<std::vector<std::unique_ptr<IntElement>>> elements;

};
/**
 * \brief Addtions for intelements
 * \param m1, m2 Helps adding numbers 
 * \return Calculated additions
 */  
ConcreteSquareMatrix operator+(const ConcreteSquareMatrix &m1, const ConcreteSquareMatrix &m2);
/**
 * \brief Subtractions for intelements
 * \param m1, m2 Helps subtracting numbers 
 * \return Calculated substractions
 */ 
ConcreteSquareMatrix operator-(const ConcreteSquareMatrix &m1, const ConcreteSquareMatrix &m2);
/**
´* \brief Multipliciations for intelements
 * \param m1, m2 Helps multiplying numbers 
 * \return Calculated multiplications
 */
ConcreteSquareMatrix operator*(const ConcreteSquareMatrix &m1, const ConcreteSquareMatrix &m2);
/**
 * \brief Output operator for ConcreteSquareMatrix
 * \param os Output stream
 * \return modified output stream
 */
std::ostream& operator<<(std::ostream& os, const ConcreteSquareMatrix& m);

#endif //ConcreteSquareMatrix_H_INCLUDED