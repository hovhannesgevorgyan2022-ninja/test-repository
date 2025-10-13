#include <iostream>
void* malloc_caller(size_t size)
{
    std::cout << "malloc called" << std::endl;
    void* p = malloc(size);
    return p;
}

void* operator new(std::size_t size)
{
    std::cout << "new called" << std::endl;
    void* p = malloc_caller(size);
    return p;
}

int main()
{
    int* p = new int(5);
    std::cout << *p;
    return 0;
}