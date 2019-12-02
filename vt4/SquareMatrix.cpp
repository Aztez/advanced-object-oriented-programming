/**
 * \file SquareMatrix.cpp 
 * \brief Source file for SquareMatrix class
 */
#include <sstream>
#include <ostream>  
#include <iostream>
#include "SquareMatrix.h"
#include "IntElement.h"

SquareMatrix::SquareMatrix(const std::string &str){
    n = 0;
    std::stringstream inputstrm{str};
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
        do{
            inputstrm >> c;
            if( !inputstrm.good())
                throw std::invalid_argument("Invalid init string!");
            
            elements.back().push_back(std::unique_ptr<IntElement>{new IntElement{number}});
            inputstrm >> c;
            if(c != ',' && c != ']')
                throw std::invalid_argument("Invalid init string!");

            col++;
            
        }while(c!=']');

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

SquareMatrix::SquareMatrix(){
  n = 1;
  elements.emplace_back();
  elements.back().push_back(std::unique_ptr<IntElement>{new IntElement{0}});
}

SquareMatrix::SquareMatrix(const SquareMatrix& m){
  n = m.n;
  
  elements.clear();
  
  for(auto& m_row : m.elements){
      elements.emplace_back();
    for(auto& m_elem : m_row){
      elements.back().push_back(std::unique_ptr<IntElement>{new IntElement(*m_elem)});
    }
  }
}

SquareMatrix::SquareMatrix(SquareMatrix&& m){
  n = m.n;
  elements = std::move(m.elements);
  m.n = 1;
  m.elements.clear();
  m.elements.emplace_back();
  m.elements.back().push_back(std::unique_ptr<IntElement>{new IntElement{0}});
}

SquareMatrix& SquareMatrix::operator=(const SquareMatrix& m){
  
  if(this != &m){
      SquareMatrix temp{m};
      std::swap(*this, temp);
  }
  return *this;
}

SquareMatrix& SquareMatrix::operator=(SquareMatrix&& m){
  
  if(this != &m){
      n = m.n;
      elements = std::move(m.elements);
  }
  return *this;
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
      if(*elem == *(*n_elem)){
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
      (*elem) += *(*m_elem);
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
      (*elem) -= *(*m_elem);
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
      **column = 0;
      auto a = std::distance(this->elements.begin(), row);
      auto b = std::distance(row->begin(), column);
      for(int k = 0; k < n; k++){
        **column += *temp.elements[a][k] * *mtrx.elements[b][k]; 
        
      }
    }
  } 
  return *this; 
}

void SquareMatrix::print(std::ostream& os) const{
  os << "[";
  for (const auto &row : this->elements) {
    os << "[";
    for (const auto &column : row) {
      os << *column;
      if (column != row.back()) {
        os << ",";
      }
    }
    os << "]";
  }
  os << "]";
}

std::string SquareMatrix::toString() const {
  std::stringstream strm;
  print(strm);
  return strm.str();
}

SquareMatrix SquareMatrix::transpose() const {
  SquareMatrix sqm{*this};
  sqm.elements.clear();
  for(auto &row : elements){
    int trans_row = 0;
    for(auto &elem : row) {
        if(row == this->elements.front()){
            sqm.elements.emplace_back();
        }
        sqm.elements[trans_row].push_back(std::unique_ptr<IntElement>{new IntElement{*elem}});
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
