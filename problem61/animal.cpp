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