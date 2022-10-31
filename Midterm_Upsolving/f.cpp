#include <iostream>
#include <queue>

using namespace std;

struct Node {
    int value, cnt;
    Node *left, *right;
    Node(int value) {
        this->value = value;
        this->cnt = 0;
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
                cur->cnt++;
                cur->left = _insert(cur->left, value);
            } else if(cur->value < value) {
                cur->cnt++;
                cur->right = _insert(cur->right, value);
            }
            return cur;
        }

    public:
        Node *root;
        BST() {
            this->root = nullptr;
        }

        void insert(int value) {
            root = _insert(root, value);
        }
};

int main() {
    BST *tree = new BST();

    int n; cin >> n;
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        tree->insert(x);
    }

    queue <Node*> q;
    q.push(tree->root);
    int total = 0;
    while(!q.empty()) {
        Node *cur = q.front();
        q.pop();
        total += (cur->value - cur->cnt);
        if(cur->left) {
            q.push(cur->left);
        }
        if(cur->right) {
            q.push(cur->right);
        }
    }
    cout << total << "\n";

    return 0;
}