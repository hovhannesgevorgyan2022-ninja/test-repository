#ifndef MATRIX_H
#define MATRIX_H

class Matrix{
    private:
        int m_size;
        int **m_mat;
    public:
        Matrix(int size);
        Matrix(const Matrix& other);
        Matrix& operator = (const Matrix& other);
        ~Matrix();
        void print();
        int get(int i , int j) {
            return m_mat[i][j];
        }
        void set(int i , int j ,int val) {
            m_mat[i][j] = val;
        }
    
    };

#endif