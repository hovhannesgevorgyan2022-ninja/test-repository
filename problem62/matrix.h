#ifndef MATRIX_H
#define MATRIX_H

class Matrix{
    protected:
        int m_size;
        int** m_mat;
    public:
        Matrix(int m_size);
        Matrix (const Matrix &other);
        Matrix& operator = (const Matrix &other);
        virtual ~Matrix();
        void print();
};

#endif