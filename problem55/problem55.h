#ifndef PROBLEM55_H
#define PROBLEM55_H

class Matrix{
    private:
        int m_size;
        int **m_mat;
    public:
        Matrix(int size);
        Matrix(const Matrix& other);
        Matrix& operator = (const Matrix& other);
        ~Matrix();
        void init();
        void print();
        int getSize() const; 
        int getElement(int i , int j) const;
        
};

#endif