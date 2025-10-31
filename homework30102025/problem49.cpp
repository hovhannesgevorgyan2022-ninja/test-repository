#include <iostream>

class Car{
    public:
        Car()
        {
            std::cout << "Call custom Constructor Car" << std::endl;
            
        }
        ~Car()
        {
            std::cout << "Call Destructor Car" << std::endl;
        }
    private:
        //std::string m_name;
};
class Parking{
    public:
        Parking()
        {
            std::cout << "Call default Constructor Parking" << std::endl;
            m_counter = 0;
        }
        void addcar(Car obj)
        {
            m_cars[m_counter] = obj;
            m_counter++;
            std::cout << "Car added" << std::endl;
        }
        ~Parking()
        {
            std::cout << "Call Destructor Parking" << std::endl;
        }
    private:
        Car m_cars[3];
        int m_parkingsize = 100;
        int m_counter;

};

int main()
{
    Car toyota;
    Parking dalma;
    dalma.addcar(toyota);
    return 0;
}