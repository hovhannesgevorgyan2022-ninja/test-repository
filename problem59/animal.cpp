#include <iostream>
#include "animal.h"

Animal::Animal(){
    std::cout << "Call Animal Constructor" << std::endl;
}
Animal::~Animal(){
    std::cout << "Call Animal Desstructor" << std::endl;

}
void Animal::sound()
{
    std::cout << "make sound" << std::endl;
}