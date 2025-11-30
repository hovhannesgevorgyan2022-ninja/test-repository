#include <iostream>

class A {
    
    private:
        int x;

    public:
        static int z;
        A(){
            z = z + 1;;
            std::cout << __func__ << std::endl;
        }
        ~A(){
            std::cout << __func__ << std::endl;
        }
};

int A::z = 0;
int main()
{
    A obj1;
    A obj2;
    A obj3;

    std::cout << "Counter = " << A::z << std::endl;
    return 0;
}