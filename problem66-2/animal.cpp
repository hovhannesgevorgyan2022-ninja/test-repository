#include <iostream>
#include "animal.h"

Animal::Animal(){
        std::cout << __func__ << std::endl;
    }

Animal::~Animal(){
        std::cout << __func__ << std::endl;
    }
void Animal::voice(){
    std::cout << "default animal voice" << std::endl;
}

Animal::Animal(Animal&& other){
    std::cout << "Move constructor" << std::endl;
}

Animal& Animal::operator = (Animal&& other){
    std::cout << "Move assignment called" << std::endl;
    if(this != &other)
        return *this;
}