#include <iostream>
#include "car.h"
#include "engine.h"

class BMW:public Car{
    public:
        BMW(){
            std::cout << __func__ << std::endl;
        }
        ~BMW(){
            std::cout << __func__ << std::endl;
        }
};

class Mercedes:public Car{
    public:
        Mercedes(){
            std::cout << __func__ << std::endl;
        }
        ~Mercedes(){
            std::cout << __func__ << std::endl;
        }
};

class Audi:public Car{
    public:
        Audi(){
            std::cout << __func__ << std::endl;
        }
        ~Audi(){
            std::cout << __func__ << std::endl;
        }
};

int main()
{
    BMW obj;
    Engine bmwengine;
    bmwengine.set_hp(300);
    obj.setEngine(&bmwengine);
    obj.setColor("red");
    std::cout << obj.m_color << std::endl;
    return 0;
}