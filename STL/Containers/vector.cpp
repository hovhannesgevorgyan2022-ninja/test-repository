#include <iostream>
#include <initializer_list>

namespace H
{
    template <typename T> class myvector
    {
        private:
            std::size_t m_size = 0;
            std::size_t m_cap = 0;
            T* m_data = nullptr;

        public:
            myvector(){ //std::cout << "myvector constructor" << std::endl;
            }
            ~myvector()
            {
                //std::cout << "myvector destructor" << std::endl;
                if(m_data != nullptr)
                {
                    delete[] m_data;
                    //std::cout << "deallocation" << std::endl;
                }

            }

            myvector(std::size_t size) : m_size(size) , m_cap(2*size) , m_data(new T[m_cap]){  //
            // std::cout << "myvector parametrized constructor" << std::endl; 
            }

            myvector(std::initializer_list<T> init)
            {
                m_size = init.size();
                m_cap = 2*m_size;
                m_data = new T[m_cap];

                std::size_t i = 0;
                for(const T& val : init)
                {
                    m_data[i++] = val;
                }
            }

            T& operator [] (std::size_t index)
            {
                return m_data[index];
            }
            const T& operator [] (std::size_t index) const
            {
                return m_data[index];
            }

            std::size_t size()
            {
                return m_size;
            }

            std::size_t capacity()
            {
                return m_cap;
            }

            void resize(std::size_t new_size)
            {
                if(new_size != m_size)
                {
                    m_size = new_size;
                    m_cap = 2*new_size;
                    T* temp = new T[m_cap];
                    for(int i = 0; i < m_size ; i++)
                    {
                        temp[i] = m_data[i];
                    }

                    delete[] m_data;
                    m_data = temp;
                }
            }

            void resize(std::size_t new_size , const T& val)
            {
                if(new_size > m_size)
                {
                    std::size_t index = m_size;
                    m_size = new_size;
                    m_cap = 2*new_size;
                    T* temp = new T[m_cap];
                    for(int i = 0; i < m_size ; i++)
                    {
                        if(i < index)
                        {
                            temp[i] = m_data[i];
                        }
                        else temp[i] = val;
                    }

                    delete[] m_data;
                    m_data = temp;
                }
            }

            void reserve(std::size_t new_cap)
            {
                if(new_cap > m_cap)
                {
                    m_cap = new_cap;
                    T* temp = new T[new_cap];
                    for(int i = 0; i < m_size ; i++)
                    {
                        temp[i] = m_data[i];
                    }

                    delete[] m_data;
                    m_data = temp;
                }
            }

            void push_back(T val)
            {
                if(m_size < m_cap)
                {
                    m_data[m_size] = val;
                }
                else
                {
                    this->resize(m_size*2);
                    m_data[m_size] = val;
                }
                ++m_size;
            }
            
            
    };

}
 int main()
 {
    
    
    H::myvector<int> v = {1,3,4,5,6,6};
    for(auto i = 0 ; i < v.size() ; i++)
    {
        std::cout << v[i] << " ";
    }


    return 0;
 }
