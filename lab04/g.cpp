#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

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
        int distance;

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

        Node* _getDeepestElement(Node *cur) {
            if(!cur) {
                return nullptr;
            }

            Node *tmp = nullptr;
            queue <Node*> q;
            q.push(cur);
            while(!q.empty()) {
                tmp = q.front();
                q.pop();
                if(tmp->left) {
                    q.push(tmp->left);
                } 
                if(tmp->right) {
                    q.push(tmp->right);
                }
            }
            return tmp;
        }

        int _findDistance(Node* cur, int n1, int n2) {
            if(!cur) {
                return 0;
            }
            int left = _findDistance(cur->left, n1, n2);
            int right = _findDistance(cur->right, n1, n2);
            if(cur->value == n1 || cur->value == n2) {
                if(left || right) {
                    distance = max(left, right);
                    return 0;
                } else {
                    return 1;
                }
            } else if(left && right) {
                distance = left + right;
                return 0;
            } else if(left || right) {
                return max(left, right) + 1;
            }
            return 0;
        }

    public:
        BST() {
            this->root = nullptr;
            this->distance = 0;
        }

        void insert(int value) {
            root = _insert(root, value);
        }

        vector <Node*> getLeaves() {
            vector <Node*> leafes;
            queue <Node*> q;
            q.push(root);
            while(!q.empty()) {
                Node* cur = q.front();
                q.pop();
                if(!cur->left && !cur->right) {
                    leafes.push_back(cur);
                }
                if(cur->left) {
                    q.push(cur->left);
                }
                if(cur->right) {
                    q.push(cur->right);
                }
            }
            return leafes;
        }

        int findDistance(int n1, int n2) {
            distance = 0;
            _findDistance(root, n1, n2);
            return distance + 1;
        }

        Node* getDeepestElement() {
            return _getDeepestElement(root);
        }

        Node* getRoot() {
            return this->root;
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

    Node *deepest = bst->getDeepestElement();
    vector <Node*> leaves = bst->getLeaves();
    
    vector <int> distances;
    distances.push_back(bst->findDistance(deepest->value, bst->getRoot()->value));
    for(int i = 0; i < leaves.size(); i++) {
        distances.push_back(bst->findDistance(deepest->value, leaves[i]->value));
    }
    cout << *max_element(distances.begin(), distances.end()) << "\n";

    return 0;
}