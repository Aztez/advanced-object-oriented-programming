/**
 * \file ConcreteSquareMatrix.cpp 
 * \brief Source file for ConcreteSquareMatrix class
 */
#include <sstream>
#include <ostream>  
#include <iostream>
#include "ConcreteSquareMatrix.h"
#include "Element.h"

ConcreteSquareMatrix::ConcreteSquareMatrix() : ConcreteSquareMatrix{0}{
}

ConcreteSquareMatrix::ConcreteSquareMatrix(const std::string &str){
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

    //Checks is it ConcreteSquareMatrix
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

ConcreteSquareMatrix::ConcreteSquareMatrix(std::vector<std::vector<std::unique_ptr<IntElement>>> v){
  elements = std::move(v);
  n = elements.size();
}

ConcreteSquareMatrix::ConcreteSquareMatrix(const ConcreteSquareMatrix& m){
  n = m.n;
  int i = 0;
  elements.clear();
  
  for(auto& m_row : m.elements){
      elements.push_back(std::vector<std::unique_ptr<IntElement>>());
    for(auto& m_elem : m_row){
      elements[i].push_back(std::unique_ptr<IntElement>{dynamic_cast<IntElement*>(m_elem->clone())});
    }
    i++;
  }
}

ConcreteSquareMatrix::ConcreteSquareMatrix(ConcreteSquareMatrix&& m){
  n = std::move(m.n);
  elements = std::move(m.elements);
}

ConcreteSquareMatrix& ConcreteSquareMatrix::operator=(const ConcreteSquareMatrix& m){
  ConcreteSquareMatrix temp{m};
  
  std::swap(elements, temp.elements);
  std::swap(n, temp.n);
  
  return *this;
}

ConcreteSquareMatrix& ConcreteSquareMatrix::operator=(ConcreteSquareMatrix&& m){
  
  if(elements == m. elements)
    return *this;
    
  std::swap(elements, m.elements);
  std::swap(n, m.n);
  
  return *this;
}

bool ConcreteSquareMatrix::operator == (const ConcreteSquareMatrix& m) const {
  
  if(n != m.n)
    return false;
    
  //Pointer to other matrix elements  
  auto n_row = m.elements.begin();
  
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

ConcreteSquareMatrix& ConcreteSquareMatrix::operator+=(const ConcreteSquareMatrix& m){
  
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


ConcreteSquareMatrix& ConcreteSquareMatrix::operator-=(const ConcreteSquareMatrix& m){
    
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

ConcreteSquareMatrix& ConcreteSquareMatrix::operator*=(const ConcreteSquareMatrix& m){
  
  if(n != m.n)
    throw std::invalid_argument("Dimensions do not match");  

  ConcreteSquareMatrix temp{*this};
  ConcreteSquareMatrix mtrx = m.transpose();
  
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

void ConcreteSquareMatrix::print(std::ostream& os) const{
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

std::string ConcreteSquareMatrix::toString() const {
  std::stringstream strm;
  print(strm);
  return strm.str();
}

ConcreteSquareMatrix ConcreteSquareMatrix::transpose() const {
  ConcreteSquareMatrix sqm{*this};
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

ConcreteSquareMatrix operator+(const ConcreteSquareMatrix& m1, const ConcreteSquareMatrix& m2){
  ConcreteSquareMatrix result(m1);
  result += m2;
  return result;
}

ConcreteSquareMatrix operator-(const ConcreteSquareMatrix& m1, const ConcreteSquareMatrix& m2){
  ConcreteSquareMatrix result(m1);
  result -= m2;
  return result;
}

ConcreteSquareMatrix operator*(const ConcreteSquareMatrix& m1, const ConcreteSquareMatrix& m2){
  ConcreteSquareMatrix result(m1);
  result *= m2;
  return result;
}

std::ostream& operator<<(std::ostream& os, const ConcreteSquareMatrix& m){
  m.print(os);
  return os;
}
