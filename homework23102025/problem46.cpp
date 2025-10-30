#include <iostream>

class Engine{
    public:
    Engine()
    {
        std::cout << "Call default Constructor for Car" << std::endl;
    }
    Engine(int hp)
    {
        std::cout << "Call custom Constructor for Engine" << std::endl;
        m_hp=hp;
    }
    ~Engine()
    {
        std::cout << "Call Destructor for Engine" << std::endl;
    }
private:
    int m_hp;
};

class Car{
public:
    Car()
    {
        std::cout << "Call default Constructor for Car" << std::endl;
    }
    Car(std::string name , std::string color , int year )
    {  
        std::cout << "Call custom Constructor for Car" << std::endl;
        m_name = name;
        m_color = color;
        m_year = year;
        m_engine = nullptr;
    }
    void setEngine(Engine* engine)
    {
        m_engine = engine;
    }
    ~Car()
    {
        std::cout << "Call Destructor for Car" << std::endl;
    }
private:
    Engine* m_engine;
    std::string m_name;
    std::string m_color;
    int m_year;
};


class Driver{
public:
    Driver()
    {
        std::cout << "Call custom Constructor for Driver" << std::endl;
        m_car = nullptr;
    }
    void getCar(Car* car)
    {
        m_car = car;
        m_carCount++;
    }
    ~Driver()
    {
        std::cout << "Call Destructor for Driver" << std::endl;
    }
private:
    int m_carCount = 0;
    Car* m_car; 
};

int main()
{
    Engine jz_1(280);
    Car toyota("altezza" , "white" , 2001);
    toyota.setEngine(&jz_1);
    Driver max;
    max.getCar(&toyota);
    
    return 0;
}