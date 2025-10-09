#ifndef FUNCTIONS_H 
#define FUNCTIONS_H
#include <iostream>

void* operator new[](std::size_t size);
void* operator new(std::size_t size);
void operator delete(void* ptr);
void operator delete[](void* ptr);

#endif
