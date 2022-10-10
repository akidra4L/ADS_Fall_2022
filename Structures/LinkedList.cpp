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

    void addAtHead(int value) {
        Node *newNode = new Node(value);
        if(!head) {
            head = newNode;
            return;
        }
        newNode->next = head;
        head = newNode;
    }

    void addAtTail(int value) {
        Node *newNode = new Node(value);
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
            cout << "Linked List is Empty\n";
            return;
        }

        Node *tmp = head;
        while(tmp) {
            cout << tmp->value << " ";
            tmp = tmp->next;
        }
    }
};

int main() {
    LinkedList *ll = new LinkedList();
    
    // check for empty linked list
    ll->print();
    
    // adding element in the head of linked list
    ll->addAtHead(2);
    ll->addAtHead(1);

    // adding element in the tail of linked list
    ll->addAtTail(3);
    ll->addAtTail(4);

    // printing elements in linked list
    ll->print();

    cout << "\n";

    return 0;
}