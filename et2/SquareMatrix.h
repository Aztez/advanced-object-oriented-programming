#ifndef SQUAREMATRIX_H_INCLUDE
#define SQUAREMATRIX_H_DEFINE

class SquareMatrix
{
public:
  SquareMatrix();
  SquareMatrix(const IntElement& e11, const IntElement& e12, const IntElement& e21, const IntElement& e22);
  SquareMatrix(const SquareMatrix& m);
  virtual ~SquareMatrix() = default;
  SquareMatrix operator += (const SquareMatrix& m);
  SquareMatrix operator -= (const SquareMatrix& m);
  SquareMatrix operator *= (const SquareMatrix& m);
  std::string toString() const;
  std::ostream& operator << (std::ostream&);

private:
  IntElement e11;
  IntElement e12;
  IntElement e21;
  IntElement e22;

};


#endif
