#include <iostream>
#include <vector>
namespace H
{
    template <typename T>
    int partitiion(std::vector<T>& vec , int low , int high)
    {
        int pivot = vec[high];
        int i = low - 1;

        for(int j = low ; j < high ; j++)
        {
            if(vec[j] < pivot)
            {
                i++;
                std::swap(vec[i] , vec[j]);
            }
        }
        std::swap(vec[i + 1] , vec[high]);
        return i + 1;
    }

    template <typename T>
    void quick_sort(std::vector<T>& vec , int low , int high)
    {
        if(low < high)
        {
            int index_pivot = partitiion(vec , low , high);
            quick_sort(vec, low, index_pivot - 1);
            quick_sort(vec , index_pivot + 1, high);
        }
    }
}

int main()
{
    std::vector<int> vec { 99 , 0 , 67 , 80 , -4 , 8 , 3, -1, 12 };
    H::quick_sort(vec , 0 , 8);
    for(auto i : vec)
    {
        std::cout << i << " ";    
    }
    return 0;
}
