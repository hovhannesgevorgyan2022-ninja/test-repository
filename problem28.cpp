#include <iostream>
int* create_dynamic_array(int size)
{
    
    int* p = new int[size];
    for (int i = 0; i < size; i++) 
    {
        
        p[i] = rand()%10;
    }
    return p;
}
void print_array(int* p , int size)
{
    for (int i = 0; i < size; i++) 
    {
        std::cout << p[i] << " ";
    }
    std::cout  << std::endl;
}
void compare_summary(int* p , int* q,int size)
{
    int sum_p = 0;
    int sum_q = 0;
    for (int i = 0; i < size; i++) 
    {
        sum_p += p[i];
        sum_q += q[i];
    }
    if(sum_p >= sum_q)
    {
        for (int i = 0; i < size; i++) 
        {
            std::cout << p[i] << " ";
        }
    }
    else
    {
        for (int i = 0; i < size; i++) 
            {
                std::cout << q[i] << " ";
            }
    }
}
int main()
{
    int n;
    srand(time(0));
    std::cin >> n ;
    int* p = create_dynamic_array(n);
    int* q = create_dynamic_array(n);
    
    std::cout  << std::endl;
    print_array(p,n);
    print_array(q,n);
    std::cout  << std::endl;
    compare_summary(p,q ,n);
    
    return 0;
}