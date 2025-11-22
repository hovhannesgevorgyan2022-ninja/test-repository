#include <iostream>
#include "animal.h"

class Dog :public Animal
{
    public:
        Dog(){
    std::cout << "Call Dog Constructor" << std::endl;
}
        void print(){
            std::cout << "x = " << x << std::endl;
        }
        std::string name_animal(){
            name = "Dog";
            return name;
        }
        ~Dog(){
    std::cout << "Call Dog Desstructor" << std::endl;

}
};

class Cat :public Animal
{
    public:
        Cat(){
    std::cout << "Call Cat Constructor" << std::endl;
}
    std::string name_animal(){
            name = "Cat";
            return name;
        }
        ~Cat(){
    std::cout << "Call Cat Desstructor" << std::endl;

}
};

class Lion :public Animal
{
    public:
        Lion(){
    std::cout << "Call Lion Constructor" << std::endl;
}
    std::string name_animal(){
            name = "Lion";
            return name;
        }
        ~Lion(){
    std::cout << "Call Lion Desstructor" << std::endl;

}
};

class Tiger :public Animal
{
    public:
        Tiger(){
    std::cout << "Call Tiger Constructor" << std::endl;
}
    std::string name_animal(){
            name = "Tiger";
            return name;
        }
        ~Tiger(){
    std::cout << "Call Tiger Desstructor" << std::endl;

}
};

int main()
{
    Dog obj;
    std::cout << obj.name_animal() << std::endl;

    Lion obj2;
    return 0;
}