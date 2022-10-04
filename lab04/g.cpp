#include <iostream>
#include <algorithm>
#include <queue>

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
            if(cur->value < value) {
                cur->right = _insert(cur->right, value);
            } else {
                cur->left = _insert(cur->left, value);
            }
            return cur;
        }

        int _maxDepth(Node* node) {
            if(!node) {
                return 0;
            }
            int leftDepth = _maxDepth(node->left);
            int rightDepth = _maxDepth(node->right);
            return max(leftDepth, rightDepth) + 1;
        }

        int _getDistance(Node *node, int max) {
            Node *cur = node;
            queue <Node*> q;
            while(!q.empty() || cur) {
                while(cur) {
                    q.push(cur);
                    cur = cur->left;
                }
                if(!q.empty() && !cur) {
                    int distance = _maxDepth(q.front()->left) + _maxDepth(q.front()->right) + 1;
                    if(max < distance) {
                        max = distance;
                    }
                    cur = q.front()->right;
                    q.pop();
                }
            }
            return max;
        }

    public:
        BST() {
            this->root = nullptr;
        }

        void insert(int value) {
            root = _insert(root, value);
        }

        int getDistance(int max) {
            return _getDistance(root, max);
        }
};

int main() {
    int n;
    cin >> n;
    BST *bst = new BST();
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        bst->insert(x);
    }

    cout << bst->getDistance(-1) << "\n";

    return 0;
}