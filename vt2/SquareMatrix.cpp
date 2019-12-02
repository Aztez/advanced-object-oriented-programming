/**
 * \file SquareMatrix.cpp 
 * \brief Source file for SquareMatrix class
 */
#include <sstream>
#include "SquareMatrix.h"
#include "IntElement.h"

SquareMatrix::SquareMatrix(){
}

SquareMatrix::~SquareMatrix(){
}

SquareMatrix::SquareMatrix(const SquareMatrix& m): e11{m.e11}, e12{m.e12}, e21{m.e21}, e22{m.e22}{
  
}

SquareMatrix::SquareMatrix(const IntElement& i11,
                           const IntElement& i12,
                           const IntElement& i21,
                           const IntElement& i22):e11(i11),e12(i12),e21(i21),e22(i22){

}

std::string SquareMatrix::toString() const {
  std::stringstream strm;

  strm << "[[" << e11 << "," << e12 << "][" << e21 << "," << e22 << "]]";
  return strm.str();
}

SquareMatrix& SquareMatrix::operator+=(const SquareMatrix& m) {
  e11 += m.e11;
  e12 += m.e12;
  e21 += m.e21;
  e22 += m.e22;
  return *this;
}


SquareMatrix& SquareMatrix::operator-=(const SquareMatrix& m){
  e11 -= m.e11;
  e12 -= m.e12;
  e21 -= m.e21;
  e22 -= m.e22;
  return *this;
}


SquareMatrix& SquareMatrix::operator*=(const SquareMatrix& m){
  IntElement a11(e11 * m.e11 + e12 * m.e21);
  IntElement a12(e11 * m.e12 + e12 * m.e22);
  IntElement a21(e21 * m.e11 + e22 * m.e21);
  IntElement a22(e21 * m.e12 + e22 * m.e22);
  e11 = a11;
  e12 = a12;
  e21 = a21;
  e22 = a22;
  return *this; 
}

void SquareMatrix::print(std::ostream& os){
  os << "[[" << e11 << "," << e12 << "][" << e21 << "," << e22 << "]]";
}