#include <iostream>
#include "problem56.h"
#include "car1.h"



Matrix::Matrix(int size)
        {
            std::cout << "Call Matrix custom Constructor" << std::endl;
            m_size = size;
            m_mat = new Car*[m_size];
            for(int i = 0 ; i < m_size ; i++)
            {
                m_mat[i] = new Car[m_size];
            }
        }
Matrix::Matrix(const Matrix& other)
        {
            std::cout << "Call Matrix Copy Contructor" << std::endl;
            this->m_size = other.m_size;
            m_mat = new Car*[m_size];
            for(int i =0 ; i < m_size ; i++)
            {
                m_mat[i] = new Car[m_size];
            }
            for(int i = 0 ; i < m_size ; i++)
            {
                for(int j = 0 ; j < m_size ; j++)
                {
                    m_mat[i][j] = other.m_mat[i][j];
                }
            }
        }
Matrix& Matrix::operator=(const Matrix& other)
        {
            std::cout << "Call Matrix Copy Assignment Operator" << std::endl;
            this->m_size = other.m_size;

            for(int i = 0; i < m_size ; i++)
            {
                for(int j = 0; j < m_size ; j++)
                {
                    m_mat[i][j] = other.m_mat[i][j];
                }
            }

            return *this;
        }
Matrix::~Matrix()
        {
            std::cout << "Call Matrix Destructor" << std::endl;
            for(int i = 0 ; i < m_size ; i++)
            {
                delete[] m_mat[i];
            }
            delete[] m_mat;
        }
