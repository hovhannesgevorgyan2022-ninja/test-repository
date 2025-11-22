#include <iostream>
#include "zoo.h"
#include "animal.h"

Zoo::Zoo(int size){
    m_size = size;
    std::cout << "Call Zoo parametrized Constructor" << std::endl;
}
Zoo::~Zoo(){
    std::cout << "Call Zoo Destructor" << std::endl;
    for (int i = 0; i < 5; i++) 
    {
        delete array[i];
    }
    delete[] array;
}