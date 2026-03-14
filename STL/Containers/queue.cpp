#include <iostream>


namespace H
{
    template <typename T> 
    class myqueue
    {
        private:
            struct Node
            {
                T data;
                Node* next;

                Node(const T& val) : data(val), next(nullptr) {}
            };

            Node* m_front;
            Node* m_back;

        public:
            myqueue() : m_front(nullptr), m_back(nullptr) {}
            ~myqueue()
            {
                while(!empty())
                {
                    pop();
                }
            }
            T& front() {return m_front->data;}
            T& back() {return m_back->data;}
            bool empty() const
            {
                return (m_front == nullptr);
            }

            void push(const T& val)
            {
                Node* newNode = new Node(val);
                if(empty())
                {
                    m_front = newNode;
                    m_back = newNode;
                }
                else
                {
                    m_back->next = newNode;
                    m_back = newNode;
                }
            }

            void pop()
            {
                if(empty()) return;

                Node* tmp = m_front;
                m_front = m_front->next;
                delete tmp;

                if(m_front == nullptr)
                    m_back = nullptr;
            }
        
    }; 
}

int main()
{
    H::myqueue<int> que;

    que.push(1);
    que.push(4);
    que.push(7);
    que.push(0);
    que.push(-3);

    std::cout << que.empty() << std::endl;
    std::cout << "front = " << que.front() << " " << "back = " << que.back() << std::endl;

    que.pop();
    std::cout << "front = " << que.front() << " " << "back = " << que.back() << std::endl;

    
    return 0;
}