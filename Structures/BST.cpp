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
        Node *root;

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

        void _preorder(Node *cur) {
            if(!cur) return;
            cout << cur->value << " ";
            _preorder(cur->left);
            _preorder(cur->right);
        }

        void _inorder(Node *cur) {
            if(!cur) return;
            _inorder(cur->left);
            cout << cur->value << " ";
            _inorder(cur->right);
        }

        void _postorder(Node *cur) {
            if(!cur) return;
            _postorder(cur->left);
            _postorder(cur->right);
            cout << cur->value << " "; 
        }

    public:
        BST() {
            this->root = nullptr;
        }
        void insert(int value) {
            root = _insert(root, value);
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
};

//        7
//       / \
//      5   8
//     / \   \
//    3   6   9

int main() {
    BST *tree = new BST();

    int n; cin >> n;
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        tree->insert(x);
    }

    cout << "Preorder: ";
    tree->preorder();
    cout << "\n";
    
    cout << "Inorder: ";
    tree->inorder();
    cout << "\n";

    cout << "Postorder: ";
    tree->postorder();
    cout << "\n";

    return 0;
}