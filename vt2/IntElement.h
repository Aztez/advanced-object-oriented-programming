/**
 * \file IntElement.h 
 * \brief Header for IntElement class
 */

#ifndef INTELEMENT_H_INCLUDE
#define INTELEMENT_H_INCLUDE
#include <ostream>

/**
 * \class IntElement
 * \brief A class for encapsulating integers into matrix elements
 */
class IntElement
{  
public:
/**
 * \brief Default constructor
 */
  IntElement();
/**
 * \brief Default virtual IntElement constructor
 */
  virtual ~IntElement();
/**
 * \brief IntElement constructor
 * \param v Integer for setting val 
 */
  IntElement(int v);
/**
 * \brief Constructor for getting value
 */  
  int getVal() const;
/**
 * \brief Constructor for setting value
 * \param v Integer for setting val
 */  
  void setVal(int v);
/**
 * \brief Addtions for intelements
 * \param i Helps adding numbers 
 * \return Calculated additions
 */  
  IntElement& operator += (const IntElement& i);
/**
 * \brief Subtractions for intelements
 * \param i Helps subtracting numbers 
 * \return Calculated substractions
 */    
  IntElement& operator -= (const IntElement& i);
/**
´* \brief Multipliciations for intelements
 * \param i Helps multiplying numbers 
 * \return Calculated multiplications
 */   
 IntElement& operator *= (const IntElement& i);

private:
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
/**
 * \brief Output operator for IntElements
 * \param os Output stream
 * \param i IntElement to be outputted
 * \return modified output stream
 */
std::ostream& operator << (std::ostream& os, const IntElement& i);


#endif //INTELEMENT_H_INCLUDED
