#include <iostream>
#include "animal.h"
#include "zoo.h"

class Cat:public Animal{
    public:    
        Cat(){
            std::cout << "Call Cat Constructor" << std::endl;
        }
        void voice() override{
            std::cout << "Cat noise###########" << std::endl;
        }
        virtual ~Cat(){
            std::cout << "Call Cat Destructor" << std::endl;
        }
};

class Dog:public Animal{
    public:
        Dog(){
                std::cout << "Call Dog Constructor" << std::endl;
            }
        void voice() override 
        {
            std::cout << "Dog noise#############" << std::endl;
        }
        virtual ~Dog(){
            std::cout << "Call Dog Destructor" << std::endl;
        }

};

class Pig:public Animal{
    public:
        Pig(){
                std::cout << "Call Pig Constructor" << std::endl;
            }
        void voice() override
        {
            std::cout << "Pig noise############" << std::endl;
        }
        virtual ~Pig(){
            std::cout << "Call Pig Destructor" << std::endl;
        }
};
class Elephant:public Animal{
    public:
        Elephant(){
                std::cout << "Call Elephant Constructor" << std::endl;
            }
        void voice() override
        {
            std::cout << "Elephant noise##############" << std::endl;
        }
        virtual ~Elephant(){
            std::cout << "Call Elephant Destructor" << std::endl;
        }
};




int main()
{
    

    int size;
    std::cout << "Type 4" << std::endl;
    std::cin >> size;
    Zoo zoo1(size);
    Cat* cat1 = new Cat();
    Dog* dog1 = new Dog();
    Pig* pig1 = new Pig();
    Elephant* elephant1 =new Elephant();
    zoo1[0] = cat1;
    zoo1[1] = dog1;
    zoo1[2] = pig1;
    zoo1[3] = elephant1;  
    for(int i = 0; i < size ; i++)
    {
        zoo1[i]->voice();
    }
    
    
    return 0;
}