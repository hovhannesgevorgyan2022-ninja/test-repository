#include <iostream>

class Matrix{
    private:
        int m_size;
        int **m_mat;
    public:
        Matrix(int size){
            std::cout << "Call custom Constructor" << std::endl;
            m_size = size;
            m_mat = new int*[m_size];
            for(int i = 0 ; i < m_size ; i++)
            {
                m_mat[i] = new int[m_size];
            }
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
        ~Matrix(){
            std::cout << "Call Destructor" << std::endl;
            for(int i = 0 ; i < m_size ; i++)
            {
                delete[] m_mat[i];
            }
            delete[] m_mat;
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
        Matrix operator ++ (){
                                 //pre ++ operator overload
            for(int i = 0 ; i < m_size ; i++)
            {
                for(int j = 0; j < m_size ; j++)

                {
                    m_mat[i][j]++;
                }
            }
                return *this;

        }
        Matrix operator ++ (int){
            Matrix temp(*this);                 //post ++ operator overload
            for(int i = 0 ; i < m_size ; i++)
            {
                for(int j = 0; j < m_size ; j++)

                {
                    ++m_mat[i][j];
                }
            }
                return temp;
        }
};

int main()
{
    Matrix A(3);
    A.init();
    A.print();
    Matrix B = A++;

    

    std::cout << "###############" << std::endl;
    B.print();
    std::cout << "###############" << std::endl;
    A.print();
    return 0;
}