#include <iostream>

class Matrix{
    public:
        Matrix(int size){
            std::cout << "Call custom Constructo" << std::endl;
            m_size = size;
            m_mat = new int*[m_size];
            for(int i = 0 ; i < m_size ; i++)
            {
                m_mat[i] = new int[m_size];
            }
        }
        void init()
        {
            for(int i = 0; i < m_size ; i++)
            {
                for(int j = 0 ; j < m_size ; j++)
                {
                    m_mat[i][j] = i + j;
                }
            }
        }
        void print()
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
        Matrix& operator=(const Matrix& other){
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
        Matrix(const Matrix& other){
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
        void rotate90Degrees(Matrix& other)
        {
            Matrix temp(other);
            for(int i = 0 ; i < m_size ; i++)
            {
                for(int j = 0 ; j < m_size ; j++)
                {
                    temp.m_mat[j][m_size - 1 -i] = other.m_mat[i][j];
                }
            }
            for(int i = 0 ; i < m_size ; i++)
            {
                for(int j = 0 ; j < m_size ; j++)
                {
                    other.m_mat[i][j] = temp.m_mat[i][j];
                }
            }

        }
        ~Matrix(){
            std::cout << "Call Destructor" << std::endl;
            for(int i = 0 ; i < m_size ; i++)
            {
                delete[] m_mat[i];
            }
            delete[] m_mat;
        }
    private:
        int m_size;
        int **m_mat;
};

int main()
{
    Matrix mat1(4);
    mat1.init();
    mat1.print();
    mat1.rotate90Degrees(mat1);
    std::cout << "#############" << std::endl;
    mat1.print();
    return 0;
}