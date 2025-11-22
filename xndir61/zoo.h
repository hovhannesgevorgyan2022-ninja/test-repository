#ifndef ZOO_H
#define ZOO_H
#include "animal.h"

class Zoo{
    public:
        int m_size;
        Animal** array = new Animal*[5];
        Zoo(int size);
        Zoo(const Zoo &obj) = delete;
        Zoo operator = (const Zoo &obj) = delete;
        ~Zoo();
};

#endif