#include <iostream>
#include "matrix.h"

Matrix::Matrix(int size){
    std::cout << "Call Matrix parametrized constructor" << std::endl;
    m_size = size;
    m_mat = new int*[m_size];
    for(int i = 0 ; i < m_size ; i++)
    {
        m_mat[i] = new int[m_size];
    }
}

Matrix::Matrix(const Matrix &other){
    std::cout << "Call Matrix Copy constructor" << std::endl;
    this->m_size = other.m_size;
    this->m_mat = new int*[m_size];
    for(int i = 0 ; i < m_size ; i++)
    {
        this->m_mat[i] = new int[m_size];
    }
    for(int i = 0 ; i < m_size ; i++)
    {
        for(int j = 0 ; j < m_size ; j++)
        {
            this->m_mat[i][j] = other.m_mat[i][j];
        }
    }
}

Matrix& Matrix::operator =(const Matrix &other){
    if(this != &other)
    {
        for(int i = 0 ; i < m_size ; i++)
        {
            delete[] this->m_mat[i];
        }
        delete[] m_mat;

        this->m_size = other.m_size;

        this->m_mat = new int*[m_size];
        
        for(int i = 0 ; i < m_size ; i++)
        {
            this->m_mat[i] = new int[m_size];
        }
        for(int i = 0 ; i < m_size ; i++)
        {
            for(int j = 0 ; j < m_size ; j++)
            {
                this->m_mat[i][j] = other.m_mat[i][j];
            }
        }
        
        return *this;
    }
}

Matrix::~Matrix(){
    std::cout << "Call Matrix Destructor" << std::endl;
            for(int i = 0 ; i < m_size ; i++)
            {
                delete[] m_mat[i];
            }
            delete[] m_mat;
}

void Matrix::print()
        {
            for(int i = 0; i < m_size ; i++)
            {
                for(int j = 0 ; j < m_size ; j++)
                {
                    std::cout << m_mat[i][j] << " " ;
                }
                std::cout << std::endl;
            }  
                
        }