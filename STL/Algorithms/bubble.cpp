#include <iostream>
#include <vector>
namespace H
{
    template <typename T>
    void bubble_sort(std::vector<T>& vec)
    {
        for(auto i = 0; i < vec.size() - 1; i++)
        {
            for(auto j = 0; j < vec.size() - i - 1 ; j++)
            {
                if(vec[j] > vec[j + 1])
                {
                    std::swap(vec[j] , vec[j + 1]);
                }
            }
        }
    }

    
}



int main()
{
    std::vector<int> vec { 99 , 0 , 67 , 80 , -4  };
    H::bubble_sort(vec);

    for(auto i : vec)
    {
        std::cout << i << " ";    
    }
    return 0; 
}