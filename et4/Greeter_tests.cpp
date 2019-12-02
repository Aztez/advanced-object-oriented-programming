#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "Greeter.h"
#include <stdexcept>

TEST_CASE("Greeter tests") {
/**
 * \brief Test empty Greeter
 */    
    CHECK_THROWS(Greeter(""));
/**
 * \brief Test for basic functionality of Greeter
 */
    Greeter greet1{"Hello, World"};
    CHECK(greet1.sayHello() == "Hello, World");
/**
 * \brief Test for adding new greet to list
 */    
    Greeter greet2{"Hello, World"};
    greet2.addGreet("How are you doing?");
    CHECK(greet2.sayHello() == "Hello, World\nHow are you doing?");
/**
 * \brief Test for copying
 */    
    Greeter greet3(greet2);
    CHECK(greet3.sayHello() == "Hello, World\nHow are you doing?");
/**
 * \brief Test for moving
 */
    greet3 = std::move(greet1);
    CHECK(greet3.sayHello() == "Hello, World");
/**
 * \brief Test for copying
 */        
    Greeter greet4 = greet3;
    CHECK(greet4.sayHello() == "Hello, World");
    
}
