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
    

    Zoo zoo1(4);
    Cat cat1;
    Dog dog1;
    Pig pig1;
    Elephant elephant1;
    zoo1.array[0] = &cat1;
    zoo1.array[1] = &dog1;
    zoo1.array[2] = &pig1;
    zoo1.array[3] = &elephant1;  
    for(int i = 0 ; i < 4 ; i++)
    {
        zoo1.array[i]->voice();
    }
    // for (int i = 0; i < 4; i++) {
    // delete zoo1.array[i];   
    // }
    // delete[] zoo1.array;
    return 0;
}