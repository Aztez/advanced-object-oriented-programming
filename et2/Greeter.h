#ifndef GREETER_H
#define GREETER_H

#include <string>

class Greeter
{
  public:
    Greeter(const std::string& g);
    std::string sayHello() const;

  private:
    std::string greetings;
};

#endif //GREETER_H
