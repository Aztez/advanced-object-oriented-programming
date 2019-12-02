#include "Greeter.h"
#include <sstream>
#include <ostream>
#include <memory>
#include <vector>
#include <stdexcept>

Greeter::Greeter(const std::string &g) {
    
    if (!g.empty()){
        this->greetings.push_back(std::unique_ptr<std::string>(new std::string(g)));
    }else{
        throw std::runtime_error("no greeting string");
    }
}  

Greeter::Greeter(const Greeter& f) {
    
    if(this != &f){
        this->greetings.reserve(f.greetings.size());
        for(const auto &greeting : f.greetings) {
            this->greetings.push_back(std::unique_ptr<std::string>(new std::string(*greeting)));
        }
    }
}

Greeter::Greeter(Greeter&& f) {
    this->greetings = std::move(f.greetings);
    f.greetings.clear();
}

Greeter &Greeter::operator=(const Greeter& f) {
    if (this != &f) {
        this->greetings.clear();
        this->greetings.reserve(f.greetings.size());
        for (const auto &greeting : f.greetings) {
            this->greetings.push_back(std::unique_ptr<std::string>(new std::string(*greeting)));
        }
    }
    return *this;
}

Greeter &Greeter::operator=(Greeter &&f) {
    if (this != &f) {
        this->greetings = std::move(f.greetings);
        f.greetings.clear();
    }
    return *this;
}


void Greeter::addGreet(const std::string &in) {
    this->greetings.push_back(std::unique_ptr<std::string>(new std::string(in)));
}

std::string Greeter::sayHello() const {
    if (this->greetings.empty()) {
        throw std::runtime_error("no greetings");
    }
    std::stringstream ss("");
    for (const auto &greeting : this->greetings) {
        ss << *greeting;
        if (greeting != this->greetings.back()){
            ss << '\n';
        }
    }
    return ss.str();
}
