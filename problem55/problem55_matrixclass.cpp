#include <iostream>
#include "problem55.h"



Matrix::Matrix(int size)
        {
            std::cout << "Call custom Constructor" << std::endl;
            m_size = size;
            m_mat = new int*[m_size];
            for(int i = 0 ; i < m_size ; i++)
            {
                m_mat[i] = new int[m_size];
            }
        }
Matrix::Matrix(const Matrix& other)
        {
            std::cout << "Call Copy Contructor" << std::endl;
            this->m_size = other.m_size;
            m_mat = new int*[m_size];
            for(int i =0 ; i < m_size ; i++)
            {
                m_mat[i] = new int[m_size];
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
            std::cout << "Call Copy Assignment Operator" << std::endl;
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
            std::cout << "Call Destructor" << std::endl;
            for(int i = 0 ; i < m_size ; i++)
            {
                delete[] m_mat[i];
            }
            delete[] m_mat;
        }
void Matrix::init()
        {
            for(int i = 0; i < m_size ; i++)
            {
                for(int j = 0 ; j < m_size ; j++)
                {
                    m_mat[i][j] = i + j;
                }
            }
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
int Matrix::getSize() const 
        {
            return m_size;
        }
int Matrix::getElement(int i , int j) const
        {
            return m_mat[i][j];
        }