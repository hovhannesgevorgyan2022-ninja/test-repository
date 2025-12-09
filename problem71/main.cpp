#include <iostream>

template<int n>
class fibonaci
{
    public:
        static const int val = fibonaci<n - 1>::val + fibonaci<n - 2>::val;
};

template<>
class fibonaci<0>
{
    public:
        static const int val = 1;
};

template<>
class fibonaci<1>
{
    public:
        static const int val = 1;
};

int main()
{
    std::cout << fibonaci<10>::val << std::endl;
    return 0;
}