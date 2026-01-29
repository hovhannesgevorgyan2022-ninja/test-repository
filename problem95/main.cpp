#include <iostream>

class f 
{
    public:
        int y = 1;
        f()
        {};

        f& operator()(int y1)
        {
            y = y*y1;
            return *this;
        }

        friend std::ostream& operator << (std::ostream& os ,  f& obj);
        
};

        std::ostream& operator << (std::ostream& os ,  f& obj)
        {
            os << (obj.y);
            obj.y = 1;
            return os;
        }

int main()
{
    f obj;
    std::cout << obj(4)(10) << std::endl;
    std::cout << obj(5)(6) << std::endl;
    std::cout << obj(5)(5)(5) << std::endl;
    return 0;
}