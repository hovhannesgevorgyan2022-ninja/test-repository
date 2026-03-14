#include <iostream>

namespace H
{
    template <typename T> 
    class mystack
    {
        private:
            struct Node
            {
                T data;
                Node* next;

                Node(const T& val) : data(val) , next(nullptr){}

            };
            Node* m_top;

        public:
            mystack() : m_top(nullptr){}
            ~mystack()
            {
                while (!empty())
                {
                    pop();
                }
            }
            T& top() {return m_top->data;}
 
            bool empty()
            {
                return (m_top == nullptr);
            }

            void push(const T& val)
            {
                Node* newNode = new Node(val);
                newNode->next = m_top;
                m_top = newNode;
            }
            void pop()
            {
                if(empty()) return;

                Node* tmp = m_top;
                m_top = m_top->next;
                delete tmp;
            }
    };
}

int main()
{
    H::mystack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    std::cout << s.top() << std::endl;
    s.pop();
    std::cout << s.top() << std::endl;
    return 0;
}