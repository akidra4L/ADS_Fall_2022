#include <iostream>
#include <algorithm>

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
                cur->right = _insert(cur->right, value);
            } else if(cur->value < value) {
                cur->left = _insert(cur->left, value);
            }
            return cur;
        }

        int _maxDepth(Node *cur) {
            if(!cur) {
                return 0;
            }
            int left = _maxDepth(cur->left);
            int right = _maxDepth(cur->right);
            return max(left, right) + 1;
        }

    public:
        Node *root;
        BST() {
            this->root = nullptr;
        }

        void insert(int value) {
            root = _insert(root, value);
        }

        int maxDepth() {
            return _maxDepth(root);
        }
        int maxDepth(Node *node) {
            return _maxDepth(node);
        }
};

/*
Input:
5
5 2 6 8 1

Output:
3
2
2

      5
     / \
    2   6
   /     \
  1       8
*/

int main() {
    BST *tree = new BST();

    int n; cin >> n;
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        tree->insert(x);
    }
    cout << tree->maxDepth() << "\n";

    Node *l = tree->root->left;
    Node *r = tree->root->right;

    cout << tree->maxDepth(l) << "\n";
    cout << tree->maxDepth(r) << "\n";

    return 0;
}