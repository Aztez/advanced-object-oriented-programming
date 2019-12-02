#ifndef GREETER_H_INCLUDE
#define GREETER_H_INCLUDE
#include <string>
#include <vector>
#include <memory>

class Greeter {
public:
    Greeter(const std::string& g);
    
    Greeter(const Greeter& f);
    
    Greeter(Greeter&& f);
    
    virtual ~Greeter() = default;
    
    Greeter& operator=(const Greeter& f);

    Greeter& operator=(Greeter&& f);

    void addGreet(const std::string&);

    std::string sayHello() const;

private:
    std::vector<std::unique_ptr<std::string>> greetings;
};


#endif //GREETER_H