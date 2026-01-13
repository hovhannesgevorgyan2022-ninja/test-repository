#include <iostream>

namespace ACA {
    template <typename T>

    class myset{
        private:
            struct Node {
                T value;
                Node* left;
                Node* right;

                Node(const T& val) : value(val), left(nullptr), right(nullptr) {}
            };

            Node* root = nullptr;
        private:
            
            Node* insert(Node* node , const T& value) {

                if(node == nullptr)
                    return new Node(value);

                if(value < node->value)
                    node->left = insert(node->left , value);
                else if(value > node->value)
                    node->right = insert(node->right , value);
                
                return node;
            }

            bool contains(Node* node, const T& value) const
            {
                if(node == nullptr)
                    return false;

                if(value == node->value)
                    return true;

                if(value < node->value)
                    return contains(node->left , value);
                else
                    return contains(node->right , value);
            }

            Node* findMin(Node* node) const
            {
                while(node->left != nullptr)
                    node = node->left;
                return node;
            }

            Node* remove(Node* node , const T& value)
            {
                if(node == nullptr)
                    return nullptr;

                if (value < node->value)
                {
                    node->left = remove(node->left, value);
                }

                else if (value > node->value)
                {
                    node->right = remove(node->right, value);
                }

                else {

                        if(node->left == nullptr)
                        {
                            Node* right = node->right;
                            delete node;
                            return node->right;
                        }

                        else if(node->right == nullptr)
                        {
                            Node* left = node->left;
                            delete node;
                            return node->right;
                        }
                        else {
                            Node* temp = findMin(node->right);
                            node->value = temp->value;
                            node->right =remove(node->right, temp->value);
                        }
                }

                return node;
            }

            void clear(Node* node)
            {
                if(!node) return;
                clear(node->left);
                clear(node->right);
                delete node;
            }
        public:
            
                myset() = default;
                ~myset() 
                {
                    clear(root);
                }
            

            void insert(const T& value)
            {
                root = insert(root , value);
            }

            void remove(const T& value)
            {
                root = remove(root , value);
            }

            bool contains(const T& value) const 
            {
                return contains(root , value);
            }

    };
}

int main()
{
    ACA::myset<int> S;

    S.insert(1);
    S.insert(10);
    S.insert(7);
    S.insert(0);
    S.insert(10);
    S.insert(-4);

    std::cout << S.contains(-4) << std::endl;
    std::cout << S.contains(100) << std::endl;

    S.remove(-4);

    std::cout << S.contains(-4) << std::endl;

    return 0;
    
}