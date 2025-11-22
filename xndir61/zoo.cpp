#include <iostream>
#include "zoo.h"
#include "animal.h"

Zoo::Zoo(int size){
    m_size = size;
    std::cout << "Call Zoo parametrized Constructor" << std::endl;
}
Zoo::~Zoo(){
    std::cout << "Call Zoo Destructor" << std::endl;  
}