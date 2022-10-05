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

struct LinkedList {
    Node *head;
    LinkedList() {
        this->head = nullptr;
    }

    void addAtHead(int x) {
        Node *newNode = new Node(x);
        if(!head) {
            head = newNode;
            return;
        } else {
            newNode->next = head;
            head = newNode;
        }
    }

    void addAtTail(int x) {
        Node *newNode = new Node(x);
        if(!head) {
            head = newNode;
            return;
        }

        Node *tmp = head;
        while(tmp->next) {
            tmp = tmp->next;
        }
        tmp->next = newNode;
    } 

    void print() {
        if(!head) {
            cout << "Linked List is Empty.\n";
            return;
        }

        Node *cur = head;
        while(cur) {
            cout << cur->value << " ";
            cur = cur->next;
        }
    }
};

int main() {
    LinkedList *ll = new LinkedList();

    // adding element in the head of linked list;
    ll->addAtHead(2);
    ll->addAtHead(1);

    // adding element in the tail of linked list
    ll->addAtTail(3);

    // printing elements in linked list
    ll->print();
    cout << endl;

    return 0;
}