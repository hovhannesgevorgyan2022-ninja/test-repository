#include <iostream>
#include <algorithm>
#include <list>

void remover(std::list<int>& l)
{
    for(auto it = l.begin(); it != l.end(); )
    {
        if(*it % 2 == 1)
        {
            it = l.erase(it);
        }
        else
        {
            ++it;
        }
    }
}

int main()
{
    std::list<int> l = {1,2,3,4,5,6,7,8,9,10};
    for(auto it = l.begin(); it != l.end(); ++it)
    {
        std::cout << *it << std::endl;
    }

    remover(l);

    for(auto it = l.begin(); it != l.end(); ++it)
    {
        std::cout << *it << std::endl;
    }
    return 0;
}