#ifndef PROBLEM56_H
#define PROBLEM56_H
#include "car1.h"

class Matrix{
    private:
        int m_size;
        Car **m_mat;
    public:
        Matrix(int size);
        Matrix(const Matrix& other);
        Matrix& operator = (const Matrix& other);
        ~Matrix();
        
};

#endif