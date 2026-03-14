#include <iostream>

namespace H
{
    template <typename T> 
    class myset
    {
        private:
            struct Node
            {
                T data;
                Node* left;
                Node* right;

                Node(const T& val) : data(val) , left(nullptr) , right(nullptr) {}
            };
            Node* m_head;
        public:
            myset() : m_head(nullptr) {}
            ~myset() { clear(m_head);}

            void clear(Node* node)
            {
                if(node == nullptr) return;
                clear(node->left);
                clear(node->right);
                delete node;
            }

            bool empty() { return (m_head == nullptr);}

            void insert(const T& val)
            {
                Node* newNode = new Node(val);
                if(m_head == nullptr)
                {
                    m_head = newNode;
                    return;
                }
                Node* curr = m_head;
                while(true)
                {
                    if(val < curr->data)
                    {
                        if(curr->left == nullptr)
                        {
                            curr->left = newNode;
                            return;
                        }
                        curr = curr->left;
                    }
                    else if(val > curr->data)
                    {
                        if(curr->right == nullptr)
                        {
                            curr->right = newNode;
                            return;
                        }
                        curr = curr->right;
                    }
                    else
                    {
                        delete newNode;
                        return;
                    }
                }
            }

            bool contains(const T& val) const
            {
                Node* curr = m_head;

                while(curr != nullptr)
                {
                    if(val < curr->data)
                    {
                        curr = curr->left;
                    }
                    else if(val > curr->data)
                    {
                        curr = curr->right;
                    }
                    else return true;
                }
                return false;
            }
            
    };
}

int main()
{
    H::myset<int> ms;
    ms.insert(0);
    ms.insert(2);
    ms.insert(2);
    ms.insert(-5);

    std::cout << ms.contains(0) << std::endl;

}