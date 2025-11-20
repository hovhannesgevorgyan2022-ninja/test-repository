#include <iostream>
#include "car1.h"

Car::Car(){
    std::cout << "Call Car Constructor" << std::endl;
}
Car::~Car(){
    std::cout << "Call Car Destructor" << std::endl;
}