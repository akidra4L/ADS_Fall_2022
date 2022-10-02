#include <iostream>

using namespace std;

struct Node {
    int value;
    Node *left, *right;
    Node(int value) {
        this->value = value;
        this->left = nullptr;
        this->right = nullptr;
    }
};

struct BST {
    Node *root;

    private:
        Node* insert(Node *cur, int value) {
            if(!cur) {
                return new Node(value);
            }
            if(cur->value < value) {
                cur->right = insert(cur->right, value);
            } else {
                cur->left = insert(cur->left, value);
            }
            return cur;
        }

        void inorder(Node* cur) {
            if(!cur) {
                return;
            }
            inorder(cur->left);
            cout << cur->value << " ";
            inorder(cur->right);
        }

    public:
        BST() {
            this->root = nullptr;
        }

        void insert(int value) {
            this->root = this->insert(this->root, value);
        }

        Node* getRoot() {
            return this->root;
        }

        void inorder() {
            this->inorder(this->root);
        }
};

int main() {
    int n, m;
    cin >> n >> m;
    BST *tree = new BST();
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        tree->insert(x);
    }
    
    while(m--) {
        string s;
        cin >> s;
        Node *root = tree->getRoot();
        for(int i = 0; i < s.size(); i++) {
            if(!root) {
                break;
            }
            if(s[i] == 'L') {
                root = root->left;
            } else {
                root = root->right;
            }
        }
        if(root) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}