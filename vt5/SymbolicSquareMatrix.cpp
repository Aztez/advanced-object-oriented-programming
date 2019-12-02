/**
 * \file SymbolicSquareMatrix.cpp 
 * \brief Source file for SymbolicSquareMatrix class
 */
#include "SymbolicSquareMatrix.h"

SymbolicSquareMatrix::SymbolicSquareMatrix() : SymbolicSquareMatrix{"[[g]]"}{
}

SymbolicSquareMatrix::SymbolicSquareMatrix(const std::string &str){
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

    //Checks is it SymbolicSquareMatrix
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

SymbolicSquareMatrix::SymbolicSquareMatrix(const SymbolicSquareMatrix& m){
  n = m.n;
  int i = 0;
  elements.clear();
  
  for(auto& m_row : m.elements){
      elements.push_back(std::vector<std::unique_ptr<Element>>());
    for(auto& m_elem : m_row){
      elements[i].push_back(std::unique_ptr<Element>{m_elem->clone()});
    }
    i++;
  }
}

SymbolicSquareMatrix::SymbolicSquareMatrix(SymbolicSquareMatrix&& m){
  n = std::move(m.n);
  elements = std::move(m.elements);
}

SymbolicSquareMatrix& SymbolicSquareMatrix::operator=(const SymbolicSquareMatrix& m){
  SymbolicSquareMatrix temp{m};
  
  std::swap(elements, temp.elements);
  std::swap(n, temp.n);
  
  return *this;
}

SymbolicSquareMatrix& SymbolicSquareMatrix::operator=(SymbolicSquareMatrix&& m){
  
  if(elements == m. elements)
    return *this;
    
  std::swap(elements, m.elements);
  std::swap(n, m.n);
  
  return *this;
}

bool SymbolicSquareMatrix::operator==(const SymbolicSquareMatrix& m) const {
  
  std::string m1 = toString();  
  std::string m2 = m.toString();  
  if(m1==m2){
    return true;
  }
  else{
    return false;
  }
    
}

void SymbolicSquareMatrix::print(std::ostream& os) const{
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

std::string SymbolicSquareMatrix::toString() const {
  std::stringstream strm;
  print(strm);
  return strm.str();
}

SymbolicSquareMatrix SymbolicSquareMatrix::transpose() const {
  SymbolicSquareMatrix sqm{*this};
  sqm.elements.clear();
  for(auto &row : elements){
    int trans_row = 0;
    for(auto &elem : row) {
        if(row == this->elements.front()){
            sqm.elements.emplace_back();
        }
        sqm.elements[trans_row].push_back(std::unique_ptr<Element>{elem->clone()});
        trans_row++;
    }
  } 
  return sqm; 
}

ConcreteSquareMatrix SymbolicSquareMatrix::evaluate(const Valuation& v) const {
  std::vector<std::vector<std::unique_ptr<IntElement>>> concreteElem;
  
  for(int i = 0; i < n; i++){
    concreteElem.push_back(std::vector<std::unique_ptr<IntElement>>());
    for(int j = 0; j < n; j++){
      concreteElem[i].push_back(std::unique_ptr<IntElement>{new IntElement{elements[i][j]->evaluate(v)}});
    }
  }
  return ConcreteSquareMatrix{std::move(concreteElem)};
}

std::ostream& operator<<(std::ostream& os, const SymbolicSquareMatrix& m){
  m.print(os);
  return os;
}
