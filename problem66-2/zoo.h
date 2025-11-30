#ifndef ZOO_H
#define ZOO_H
#include "animal.h"

class Zoo{
    private:
        int m_size;
        Animal** array;
    public:
        Zoo(int size);
        Zoo(const Zoo &obj) = delete;
        Zoo operator = (const Zoo &obj) = delete;
        ~Zoo();
        Animal*& operator[](int index); 
};

#endif