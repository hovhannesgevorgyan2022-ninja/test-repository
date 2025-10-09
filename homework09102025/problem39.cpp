#include "functions.h"
//#include <random>
int main()
{
    int n;
    std::cin >> n;
    int* arr = new int[n];
    srand(time(0)); 
    for(int i = 0; i < n ; i++)
    {
        arr[i] = rand()%10;
    }
    delete[] arr;
    return 0;
}