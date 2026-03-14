#include <iostream>

namespace H
{
    template <typename T>
    class fit
    {
        private:
            T *ptr;
        public:
            fit(): ptr(nullptr){}
            fit(T *p) : ptr(p){}
            
            fit(const fit& other)
            {
                this->ptr = other.ptr;
            }

            fit& operator=(const fit& other) 
            {
                if(this != other)
                {
                    ptr = other.ptr;
                }
                return *this;
            }

            bool operator==(const fit& other) const
            {
                return (this->ptr == other.ptr);
            }
            bool operator!=(const fit& other) const
            {
                return (this->ptr != other.ptr);
            }

            fit& operator++()  //prefix increment
            {
                ptr++;
                return *this;
            }

            fit& operator++(int) //postfix increment
            {
                fit tmp = *this;
                ptr++;
                return tmp;
            }

            T& operator->()
            {
                return ptr;
            }
            T& operator*()
            {
                return *ptr;
            }
    };
}

int main()
{
    int arr[] = {1,2,10,-1};

    H::fit<int> begin(&arr[0]);
    H::fit<int> end(&arr[0] + 4);

    for(auto it = begin; it != end; ++it)
    {
        std::cout << *it << " ";
    }
    return 0;
}