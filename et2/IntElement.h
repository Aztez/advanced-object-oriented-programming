#ifndef INTELEMENT_H_INCLUDE
#define INTELEMENT_H_DEFINE

class IntElement
{
public:
  IntElement();
  IntElement(int v);
  virtual ~IntElement() = default;
  int getVal();
  void setVal(int v);
  IntElement operator += (const IntElement& i);
  IntElement operator -= (const IntElement& i);
  IntElement operator *= (const IntElement& i);

private:
  int val;

};

#endif
