/**
 *\file SquareMatrix.h
 *\brief Header for SquareMatrix class
 */
#ifndef SQUAREMATRIX_H_INCLUDE
#define SQUAREMATRIX_H_INCLUDE
#include <ostream>
#include <string>
#include <vector>
#include <memory>
#include "IntElement.h"
/**
 * \class SquareMatrix
 * \brief A class for square matrixes
 */
class SquareMatrix{
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
  SquareMatrix(const std::string& strm);
 /**
  * \brief SquareMatrix copy constructor
  * \param m Object to be copied
  * \return m type intelements
  */
  SquareMatrix(const SquareMatrix& m);
 /**
  * \brief SquareMatrix copy constructor
  * \param m Object to be copied
  * \return m type intelements
  */  
  SquareMatrix(SquareMatrix&& m);
/**
  * \brief Default virtual SquareMatrix destructor
  */
  ~SquareMatrix() = default;
/**
  * \brief Default copy constructor
  */  
  SquareMatrix& operator= (const SquareMatrix& m);
/**
  * \brief Default copy constructor
  */  
  SquareMatrix& operator= (SquareMatrix&& m);
/**
  * \brief Flips the squarematrix around
  * \return Squarematrix
  */  
  SquareMatrix transpose() const;
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
  * \brief Copy constructor
  * \param another Help param for cpying
  * \return copy
  */
  bool operator == (const SquareMatrix& another) const;
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
  int n;
  std::vector<std::vector<std::unique_ptr<IntElement>>> elements;

};
/**
 * \brief Addtions for intelements
 * \param m1, m2 Helps adding numbers 
 * \return Calculated additions
 */  
SquareMatrix operator+(const SquareMatrix &m1, const SquareMatrix &m2);
/**
 * \brief Subtractions for intelements
 * \param m1, m2 Helps subtracting numbers 
 * \return Calculated substractions
 */ 
SquareMatrix operator-(const SquareMatrix &m1, const SquareMatrix &m2);
/**
´* \brief Multipliciations for intelements
 * \param m1, m2 Helps multiplying numbers 
 * \return Calculated multiplications
 */
SquareMatrix operator*(const SquareMatrix &m1, const SquareMatrix &m2);
/**
 * \brief Output operator for SquareMatrix
 * \param os Output stream
 * \return modified output stream
 */
std::ostream& operator<<(std::ostream&, const SquareMatrix&);

#endif //SQUAREMATRIX_H_INCLUDED