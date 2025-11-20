#include <iostream>
#include <fstream>
#include <cmath>
#include "matrix.h"
#include "reader.h"

Reader::Reader(const std::string& filename){
    m_file.open(filename);
    std::cout << "Call Reader parametrized Constructor" << std::endl;
}
Reader::~Reader(){
    m_file.close();
    std::cout << "Call Reader Destructor" << std::endl;
}
Matrix* Reader::read_matrix(){
    std::string str;
    int arr[10000];
    int arr_size = 0;
    if(m_file.is_open())
    {
        int elem;
        while(m_file >> elem)
        {
            arr[arr_size] = elem;
            arr_size++;
        }
    }
    int mat_size = sqrt(arr_size);
    Matrix *mat = new Matrix(mat_size);
    for(int i = 0 ; i < mat_size ; i++)
            {
                for(int j = 0 ; j < mat_size ; j++)
                {
                    mat->set(i , j , arr[i*mat_size + j]);
                }
            }
    return mat; 
}