#include <iostream>
class matrix {
    public:
        int size;
        int** m;
};

int main()
{
    matrix mymatrix1;
    mymatrix1.size = 2;
    std::cout << mymatrix1.size << std::endl;
    return 0;
}