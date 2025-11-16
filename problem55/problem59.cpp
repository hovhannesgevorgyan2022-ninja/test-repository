#include <iostream>

class Animal{
    
    public:
        Animal(){
            std::cout << __func__ << std::endl;

        }
        ~Animal(){
            std::cout << __func__ << std::endl;
        }

};

class Dog : public : Animal
{
    Dog(){
        
    }

    ~Dog(){}
};

int main(){

    Animal obj;

    return 0;
}