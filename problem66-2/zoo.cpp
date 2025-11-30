#include <iostream>
#include "zoo.h"
#include "animal.h"

Zoo::Zoo(int size){
    m_size = size;
    array = new Animal*[m_size];
    std::cout << "Call Zoo parametrized Constructor" << std::endl;
    for(int i = 0 ; i < m_size ; i++)
    {
        array[i] = nullptr;
    }
}
Zoo::~Zoo(){
    std::cout << "Call Zoo Destructor" << std::endl;
    for (int i = 0; i < m_size; i++) 
    {
        delete array[i];
    }
    delete[] array;
}

Animal*& Zoo::operator [](int index){
    return array[index];
}

