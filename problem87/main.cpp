#include <iostream>
#include "animal.h"
#include <set>



int main()
{
    
    Animal obj1(100);
    std::set<Animal, Animal::AnimalCompare> s1;
    s1.insert(Animal(4));
    s1.insert(Animal(10));
    s1.insert(Animal(10));
    s1.insert(Animal(0));
    s1.insert(Animal(1));
    s1.insert(Animal(34));
    s1.insert(obj1);
    

    return 0;
}