#include <iostream>

using namespace std;

struct Node {
    int value;
    Node *next; 
    Node(int value) {
        this->value = value;
        this->next = nullptr;
    }
};

struct Stack {
    Node *head;
    Stack() {
        this->head = nullptr;
    }

    void add(int value) {
        Node *newNode = new Node(value);
        if(!head) {
            head = newNode;
            return;
        }
        newNode->next = head;
        head = newNode;
    }

    void pop() {
        if(!isEmpty()) {
            head = head->next;
        }
    }

    int getMax() {
        Node *cur = head;
        int max = -1;
        while(cur) {
            if(max < cur->value) {
                max = cur->value;
            }
            cur = cur->next;
        }
        return max;
    }

    int top() {
        return head->value;
    }

    bool isEmpty() {
        return head == nullptr;
    }
};

int main() {
    Stack *st = new Stack();

    int q; cin >> q;
    int max = -1;
    while(q--) {
        string s; cin >> s;
        if(s == "add") {
            int x; cin >> x;
            st->add(x);
            if(st->top() > max) {
                max = x;
            }
        } else if(s == "delete") {
            if(st->top() == max) {
                st->pop();
                max = st->getMax();
            } else {
                st->pop();
            }
        } else if(s == "getcur") {
            if(st->isEmpty()) {
                cout << "error\n";
            } else {
                cout << st->top() << "\n";
            }
        } else if(s == "getmax") {
            if(st->isEmpty()) {
                cout << "error\n";
            } else {
                cout << max << "\n";
            }
        }
    }

    return 0;
}