#include <iostream>
#include <fstream>
#include "problem57.h"
int main()
{
    Matrix obj(3);
    obj.init();
    std::ofstream file;
    file.open("output.txt");
    for(int i = 0; i < obj.getSize() ; i++)
            {
                for(int j = 0 ; j < obj.getSize() ; j++)
                {
                    file << obj.getElement(i , j) << " ";
                }
                file << std::endl;
            }
    file.close();
    return 0;
}