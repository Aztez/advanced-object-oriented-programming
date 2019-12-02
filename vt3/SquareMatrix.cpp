/**
 * \file SquareMatrix.cpp 
 * \brief Source file for SquareMatrix class
 */
#include <sstream>
#include <ostream>
#include <iostream>
#include <stdexcept>
#include <vector>
#include "SquareMatrix.h"
#include "IntElement.h"

SquareMatrix::SquareMatrix(const std::string &str){
    n = 0;
    std::stringstream inputstrm(str);
    int number;
    char c;
    int col = 0;
    int colnum = -1;
    int rows = 0;
    
    if(str == "[[]]")
        return;

    inputstrm >> c;
    if( !inputstrm.good() || c!= '[')
        throw std::invalid_argument("Invalid init string!");

    inputstrm >> c;
    if( !inputstrm.good() || c!= '[')
        throw std::invalid_argument("Invalid init string!");

    //Read row by row and check
    while(c!=']'){
        
        //Read row
        std::vector<IntElement> rowVec;
        do{
            inputstrm >> number;
            if( !inputstrm.good())
                throw std::invalid_argument("Invalid init string!");

            inputstrm >> c;
            if(c != ',' && c != ']')
                throw std::invalid_argument("Invalid init string!");

            col++;
            rowVec.push_back(IntElement(number));
            
        }while(c!=']');
        
        //Push the row
        elements.push_back(rowVec);

        rows++;
        if(rows == 1)
            colnum = col;

        if(colnum != col)
            throw std::invalid_argument("Invalid init string!");
        col = 0;

        inputstrm >> c;
        if(inputstrm.eof())
            throw std::invalid_argument("Invalid init string!");

    }

    //Checks is it squarematrix
    if(rows != colnum)
        throw std::invalid_argument("Invalid init string!");;

    //Is there stuff after end
    std::string tail;
    inputstrm >> tail;
    if(tail != "")
        throw std::invalid_argument("Invalid init string!");;
    
    //Matrix OK - set the row
    n = rows;
}

SquareMatrix::SquareMatrix(const SquareMatrix& m){
  n = m.n;
  elements = m.elements;
}

bool SquareMatrix::operator == (const SquareMatrix& another) const {
  
  if(n != another.n)
    return false;
    
  //Pointer to other matrix elements  
  auto n_row = another.elements.begin();
  
  for(auto& row : elements){
    auto n_elem = n_row->begin();  
    for(auto& elem : row){
      //Check the elements
      if(elem == (*n_elem)){
        n_elem++;
      }else{
        return false;
      }
      }
    n_row++;
    }
  return true;
}

SquareMatrix& SquareMatrix::operator+=(const SquareMatrix& m){
  
  if(n != m.n)
    throw std::invalid_argument("Dimensions do not match");
  
  //Pointer to other matrix elements  
  auto m_row = m.elements.begin();
  
  for(auto& row : elements){
    auto m_elem = m_row->begin();  
    for(auto& elem : row){
      //Add the element
      elem += (*m_elem);
      m_elem++;
    }
    m_row++;
  }
  return *this;
}


SquareMatrix& SquareMatrix::operator-=(const SquareMatrix& m){
    
  if(n != m.n)
    throw std::invalid_argument("Dimensions do not match");
  
  //Pointer to other matrix elements  
  auto m_row = m.elements.begin();
  
  for(auto& row : elements){
    auto m_elem = m_row->begin();  
    for(auto& elem : row){
      //Minus the element
      elem -= (*m_elem);
      m_elem++;
    }
    m_row++;
  }
  return *this;
}

SquareMatrix& SquareMatrix::operator*=(const SquareMatrix& m){
  
  if(n != m.n)
    throw std::invalid_argument("Dimensions do not match");  

  SquareMatrix temp{*this};
  SquareMatrix mtrx = m.transpose();
  
  for(auto row = this->elements.begin(); row != this->elements.end(); row++){
    for(auto column = row->begin(); column != row->end(); column++){
      *column = 0;
      auto a = std::distance(this->elements.begin(), row);
      auto b = std::distance(row->begin(), column);
      for(int k = 0; k < n; k++){
        *column += temp.elements[a][k] * mtrx.elements[b][k]; 
        
      }
    }
  } 
  return *this;
}

void SquareMatrix::print(std::ostream& os) const{
  os << toString();
}

std::string SquareMatrix::toString() const {
  std::stringstream strm;
  strm << "[";
  for(auto& row : elements){
    strm << "[";
    bool first = true;
    for(auto& elem : row){
      if(!first)
          strm << ',';
        first = false;
        strm << elem;
    }
    strm << "]";
  }
  strm << "]";
  return strm.str();
}

SquareMatrix SquareMatrix::transpose() const {
  SquareMatrix sqm;
  sqm.n = n;
  sqm.elements = std::vector<std::vector<IntElement>>(n);
  for(auto row = elements.begin(); row != elements.end(); row++){
      
    auto trans_row = sqm.elements.begin();
    for(auto elem = row-> begin(); elem != row->end(); elem++) {
        trans_row->push_back(*elem);
        trans_row++;
    }
  }
  return sqm;
}

SquareMatrix operator+(const SquareMatrix& m1, const SquareMatrix& m2){
  SquareMatrix result(m1);
  result += m2;
  return result;
}

SquareMatrix operator-(const SquareMatrix& m1, const SquareMatrix& m2){
  SquareMatrix result(m1);
  result -= m2;
  return result;
}

SquareMatrix operator*(const SquareMatrix& m1, const SquareMatrix& m2){
  SquareMatrix result(m1);
  result *= m2;
  return result;
}

std::ostream& operator<<(std::ostream& os, const SquareMatrix& m){
  m.print(os);
  return os;
}