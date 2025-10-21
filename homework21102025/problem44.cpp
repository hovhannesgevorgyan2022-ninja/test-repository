#include <iostream>
class Car {
    public:
        int year;
        int engine_cc;
        std::string color;
        void print_info()
        {
            std::cout << "year: " << year << std::endl;
            std::cout << "engine_cc: " << engine_cc << std::endl;
            std::cout << "color: " << color << std::endl;
        }
        void change_color(std::string new_color)
        {
            color = new_color;
        }
        Car(int c_year , int c_engine_cc , std::string c_color)
        {
            year = c_year;
            engine_cc = c_engine_cc;
            color = c_color;
        }
        ~Car()
        {
            std::cout << "Destructor called" << std::endl;
        }           
};

int main()
{
    Car mycar(2000 , 1500 , "black");
    mycar.print_info();
    mycar.change_color("red");
    mycar.print_info();
    Car bmw(2009 , 5000 , "white");
    bmw.print_info();
    return 0;
}