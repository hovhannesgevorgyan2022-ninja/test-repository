#include <iostream>
#include "functions.h"
void* operator new (std::size_t size)
{
    void* p =  malloc(size);
    std::cout << "Hello from virtual memory" << std::endl;
    return p;
}

void operator delete(void* ptr)
{
    std::cout << "Delete completed" << std::endl;
    free(ptr);

}

void* operator new[] (std::size_t size)
{
    void* p = malloc(size);
    std::cout << "new[] worked!!!" << std::endl;
    return p;
}

void operator delete[](void* ptr)
{
    std::cout << "delete[] worked!!!" << std::endl;
    free(ptr);

}
// int main()
// {
//     int* p = new(int);
//     delete(p);
//     int* arr = new int[3];
//     return 0;
// }