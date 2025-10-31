#include <iostream>

class Car{
    public:
        Car(int year , std::string name , std::string color){
            std::cout << "Call custom Constructor" << std::endl;
            m_year = year;
            m_name = name;
            m_color = color;
        }

        Car(const Car& other){
            std::cout << "Call Copy Constructor" << std::endl;
            this->m_year = other.m_year;
            this->m_name = other.m_name;
            this->m_color = other.m_color;
        }

        Car& operator=(const Car& other){
            std::cout << "Call Copy Assignment Operator" << std::endl;
            this->m_year = other.m_year;
            this->m_name = other.m_name;
            this->m_color = other.m_color;

            return *this;
        }
        
        std::string printName(){
            return m_name;
        }

        ~Car(){
            std::cout << "Call Destructor" << std::endl;
        }
    private:
        int m_year;
        std::string m_name;
        std::string m_color;
};
int main()
{
    Car toyota(2001 , "altezza" , "white");
    Car lexus(toyota);

    std::cout << toyota.printName() << std::endl;
    Car bmw(2016 , "M5F10" , "blue");

    std::cout << bmw.printName() << std::endl;
    
    bmw = toyota;

    std::cout << bmw.printName() << std::endl;

    return 0;
}