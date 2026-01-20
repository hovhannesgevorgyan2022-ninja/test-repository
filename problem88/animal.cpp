#include <iostream>
#include "animal.h"

Animal::Animal(int w) : weight(w){}
Animal::~Animal(){}
void Animal::sound()
{
    std::cout << "make sound" << std::endl;
}

int Animal::getweight() const
{
    return weight;
}

bool Animal::operator == (const Animal& obj) const
{
    return (this->weight == obj.weight );
}

