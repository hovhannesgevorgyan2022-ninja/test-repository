#include <iostream>
#include "engine.h"

Engine::Engine(){
    std::cout << __func__ <<std::endl;
}

void Engine::set_hp(int hp){
    m_hp = hp;
}

Engine::~Engine(){
    std::cout << __func__ <<std::endl;
}