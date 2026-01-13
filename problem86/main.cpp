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

            void inorder(Node* node) const
            {
                if(node == nullptr)
                    return;

                inorder(node->left);
                std::cout << node->value << " ";
                inorder(node->right);
            }

            void preorder(Node* node) const

            {
                if(node == nullptr)
                    return;
                std::cout << node->value << " ";
                preorder(node->left);
                preorder(node->right);
            }

            void postorder(Node* node) const
            {
                if(node == nullptr)
                    return;
                preorder(node->left);
                preorder(node->right);
                std::cout << node->value << " ";
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

            void myset_inorder() const 
            {
                inorder(root);
                std::cout << std::endl;
            }

            void myset_preorder() const
            {
                preorder(root);
                std::cout << std::endl;
            }

            void myset_postorder() const
            {
                postorder(root);
                std::cout << std::endl;
            }
    };
}

int main()
{
    ACA::myset<int> S;

    S.insert(5);
    S.insert(10);
    S.insert(7);
    S.insert(0);
    S.insert(10);
    S.insert(-4);
    S.insert(2);
    S.insert(3);
    S.insert(4);

    std::cout << S.contains(-4) << std::endl;
    std::cout << S.contains(100) << std::endl;

    

    S.myset_inorder();

    S.myset_preorder();

    S.myset_postorder();

    return 0;
    
}