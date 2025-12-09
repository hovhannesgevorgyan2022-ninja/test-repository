#include <iostream>

void print()
{
    std::cout << "function end" << std::endl;
}

template<typename T , typename... Types>
void print(T val1 , Types... val2)
{
    std::cout << val1 << std::endl;

    print(val2...);
}

int main()
{
    print(1 , 4 , 6 , -100 , "aaa" , true);
    return 0;
}