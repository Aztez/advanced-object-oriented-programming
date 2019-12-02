/**
 *\file SquareMatrix.h
 *\brief Header for SquareMatrix class
 */
#ifndef SQUAREMATRIX_H_INCLUDE
#define SQUAREMATRIX_H_INCLUDE
#include <ostream>
#include <string>
#include "IntElement.h"

/**
 * \class SquareMatrix
 * \brief A class for square matrixes
 */
class SquareMatrix
{
public:
 /**
  * \brief Default constructor
  */
  SquareMatrix();
 /**
  * \brief Parametric constructor
  * \param i11, i12, i21, i22 intelements for constructing square matrixes
  * \return intelements
  */
  SquareMatrix(const IntElement& i11, const IntElement& i12, const IntElement& i21, const IntElement& i22);
 /**
  * \brief SquareMatrix copy constructor
  * \param m Object to be copied
  * \return m type intelements
  */
  SquareMatrix(const SquareMatrix& m);
 /**
  * \brief Default virtual SquareMatrix destructor
  */
  ~SquareMatrix();
/**
  * \brief Addtions for square matrixes
  * \param m Helps adding numbers 
  * \return Calculated additions
  */
  SquareMatrix& operator += (const SquareMatrix& m);
/**
  * \brief Subtractions for square matrixes
  * \param m Helps subtracting numbers 
  * \return Calculated substractions
  */  
  SquareMatrix& operator -= (const SquareMatrix& m);
/**
  * \brief Multipliciations for square matrixes
  * \param m Helps multiplying numbers 
  * \return Calculated multiplications
  */  
  SquareMatrix& operator *= (const SquareMatrix& m);
/**
  * \brief Returns string presentation of intelements
  * \return string of squarematrix
  */
  std::string toString() const;
/**
  * \brief Prints string presentation of intelements
  * \param os Output stream
  * \return modified output stream
  */  
  void print(std::ostream& os);

private:
  IntElement e11, e12, e21, e22;

};


#endif
