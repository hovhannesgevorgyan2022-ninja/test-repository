#include <iostream>
int** f (int size)
{
    int** p = new int*[size];
    for(int i = 0; i < size; i++)
    {
        p[i] = new int[size];
    }
    return p;

}

int main()
{
    int n;
    std::cin >> n;
    int** p = f(n);
    return 0;
}