#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "Greeter.h"

Greeter::Greeter(const std::string& g) : greetings(g)
{


}

std::string Greeter::sayHello() const
{
  return greetings;
}

TEST_CASE("Greeter test", "(Greeter)")
{
  std::string GreetStr;
  GreetStr = "Hello World!";
  Greeter greet(GreetStr);
  CHECK(greet.sayHello() == "Hello World!");
}
