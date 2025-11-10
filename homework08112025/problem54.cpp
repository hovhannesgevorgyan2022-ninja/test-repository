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
        int getSize() const 
        {
            return m_size;
        }
        int getElement(int i , int j) const
        {
            return m_mat[i][j];
        }
};

std::ostream& operator << (std::ostream& os , const Matrix& other)
        {
            for(int i = 0; i < other.getSize() ; i++)
            {
                for(int j = 0 ; j < other.getSize() ; j++)
                {
                    os << other.getElement(i , j) << " ";
                }
                os << std::endl;
            }
            return os;
        }

int main()
{
    Matrix A(3);
    A.init();
    std::cout << A << std::endl;
    
    return 0;
}