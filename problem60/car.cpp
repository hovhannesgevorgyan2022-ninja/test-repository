#include <iostream>
#include "engine.h"
#include "car.h"

Car::Car(){
        std::cout << __func__ <<std::endl;
}
void Car::setColor(std::string color){
    m_color = color;
}
void Car::setEngine(Engine* engine){
    m_engine = engine;
}
Car::~Car(){
        std::cout << __func__ <<std::endl;
}