#include <iostream>
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

    int cnt = 0;
    queue <Node*> q;
    q.push(tree->root);
    while(!q.empty()) {
        Node *cur = q.front();
        q.pop();
        if(!cur->left && !cur->right) {
            cnt++;
        }
        if(cur->left) {
            q.push(cur->left);
        } 
        if(cur->right) {
            q.push(cur->right);
        }
    }
    cout << cnt << "\n";


    return 0;
}