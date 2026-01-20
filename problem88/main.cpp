#include <iostream>
#include "animal.h"
#include <unordered_set>


int main()
{
    
    std::unordered_set<Animal, Animal::customhash> s1;

    s1.insert(Animal(4));
    s1.insert(Animal(10));
    s1.insert(Animal(10));
    s1.insert(Animal(1));
    s1.insert(Animal(55));

    std::cout << s1.size() << std::endl;
    

    return 0;
}