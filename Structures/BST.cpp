#include <iostream>

using namespace std;

struct Node {
    int value;
    Node *left, *right;
    Node(int value) {
        this->value = value;
        this->left = this->right = nullptr;
    }
};

struct BST {
    private:
        Node* _insert(Node *cur, int value) {
            if(!cur) {
                return new Node(value);
            }
            if(cur->value > value) {
                cur->left = _insert(cur->left, value);
            } else if(cur->value < value) {
                cur->right = _insert(cur->right, value);
            }
            return cur;
        }

        Node* _search(Node *cur, int target) {
            if(!cur) {
                return nullptr;
            }
            if(cur->value == target) {
                return cur;
            } else if(cur->value > target) {
                return _search(cur->left, target);
            }
            return _search(cur->right, target);
        }

        int _leftmost(Node *cur) {
            if(!cur) return -1;
            if(!cur->left) return cur->value;
            return _leftmost(cur->left);
        }

        Node* _remove(Node *cur, int x) {
            if(!cur) {
                return nullptr;
            }
            if(cur->value == x) {
                if(!cur->left && !cur->right) {
                    delete cur;
                    return nullptr;
                } else if(cur->left && !cur->right) {
                    Node *tmp = cur->left;
                    delete cur;
                    return tmp;
                } else if(!cur->left && cur->right) {
                    Node *tmp = cur->right;
                    delete cur;
                    return tmp;
                } else if(cur->left && cur->right) {
                    cur->value = _leftmost(cur->right);
                    cur->right = _remove(cur->right, cur->value);
                }
            } else if(cur->value > x) {
                cur->left = _remove(cur->left, x);
                return cur;
            } else if(cur->value < x) {
                cur->right = _remove(cur->right, x);
                return cur;
            }
            return cur;
        }

        void _preorder(Node *cur) {
            if(!cur) {
                return;
            }
            cout << cur->value << " ";
            _preorder(cur->left);
            _preorder(cur->right);
        }
        void _inorder(Node *cur) {
            if(!cur) {
                return;
            }
            _inorder(cur->left);
            cout << cur->value << " ";
            _inorder(cur->right);
        }
        void _postorder(Node *cur) {
            if(!cur) {
                return;
            }
            _postorder(cur->left);
            _postorder(cur->right);
            cout << cur->value << " ";
        }

        int _getSize(Node *cur) {
            if(!cur) {
                return 0;
            }
            return _getSize(cur->left) + _getSize(cur->right) + 1;
        }

    public:
        Node *root;
        BST() {
            this->root = nullptr;
        }

        void insert(int value) {
            root = _insert(root, value);
        }

        Node* search(int target) {
            return _search(root, target);
        }

        void remove(int target) {
            _remove(root, target);
        }

        void preorder() {
            _preorder(root);
        }
        void inorder() {
            _inorder(root);
        }
        void postorder() {
            _postorder(root);
        }

        int getSize() {
            return _getSize(root);
        }
        int getSize(Node *someNode) {
            return _getSize(someNode);
        }
};

int main() {
    BST *bst = new BST();
    
    bst->insert(8);
    bst->insert(6);
    bst->insert(11);
    bst->insert(7);
    bst->insert(12);
    bst->insert(10);
    bst->insert(5);

    cout << "Preorder: ";
    bst->preorder();
    cout << "\n";

    cout << "Inorder: ";
    bst->inorder();
    cout << "\n";

    cout << "Postorder: ";
    bst->postorder();
    cout << "\n";

    cout << "Size of BST: " << bst->getSize() << "\n";
    
    // int target; cin >> target;
    // cout << "Subtree's size of target - " << target << ": ";
    // Node *targetNode = bst->search(target);
    // cout << bst->getSize(targetNode) << "\n";

    bst->remove(6);
    bst->inorder();
    cout << "\n";

    return 0;
}