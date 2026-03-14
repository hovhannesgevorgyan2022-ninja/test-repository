#include <iostream>

namespace H 
{
    template <typename T>
    struct Node
    {
        Node* next;
        T data;
        
        Node(const T& value, Node* n = nullptr) : data(value), next(n)
        {}
    };

    template <typename T>
    class SingleLinkedList
    {
        private:
            Node<T>* head;
            size_t size;
        public:
            SingleLinkedList() : head(nullptr) , size(0) 
            {}
            ~SingleLinkedList()
            {
                clear();
            } 

            void push_front(const T& val)
            {
                head = new Node<T>(val , head);
                ++size;
            }

            void push_back(const T& val)
            {
                Node<T>* newNode = new Node<T>(val);
                
                if(!head)
                {
                    head = newNode;
                }

                else
                {
                    Node<T>* current = head;
                    while(current->next != nullptr)
                    {
                        current = current->next;
                    }
                    current->next = newNode;
                }
                ++size;
            }

            void pop_front()
            {
                if(!head)
                    return;

                Node<T>* temp = head;
                head = head->next;
                delete temp;
                --size;

            }

            void clear()
            {
                while(head)
                    pop_front();
            }

            bool empty()
            {
                return head == nullptr;
            }

            size_t length()
            {
                return size;
            }

            T& front()
            {
                return head->data;
            }
            const T& front() const
            {
                return head->data;
            }

            void print()
            {
                Node<T>* temp = head;
                while(temp->next != nullptr)
                {
                    std::cout << temp->data << std::endl;
                    temp = temp->next;
                }
            }
    };

}

int main()
{
    H::SingleLinkedList<int> list;
    std::cout << list.empty() << std::endl;

    list.push_back(2);
    list.push_back(3);
    list.push_back(4);
    list.push_back(5);
    list.push_back(6);
    list.push_back(7);
    list.push_back(8);
    list.push_back(9);
    list.push_back(10);
    list.print();
    
    list.pop_front();
    list.pop_front();
    list.pop_front();
    list.pop_front();

    list.print();

    return 0;
}