#ifndef CAR_H
#define CAR_H
#include "engine.h"
class Car{
    public:
        std::string m_color;
        Engine* m_engine = nullptr;
    public:
        
        Car();
        Car(const Car& obj) = delete;
        Car& operator = (const Car& obj) = delete;
        void setColor(std::string color);
        void setEngine(Engine* engine);
        ~Car();
};

#endif