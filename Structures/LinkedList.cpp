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
    int size;
    LinkedList() {
        this->head = nullptr;
        this->size = 0;
    }

    void push_front(int value) {
        Node *newNode = new Node(value);
        this->size++;
        if(!head) {
            head = newNode;
            return;
        }
        newNode->next = head;
        head = newNode;
    }

    void push_back(int value) {
        Node *newNode = new Node(value);
        this->size++;
        if(!head) {
            head = newNode;
            return;
        }

        Node *cur = head;
        while(cur->next) {
            cur = cur->next;
        }
        cur->next = newNode;
    }

    void push_index(int value, int index) {
        Node *newNode = new Node(value);
        if(index == 0) {
            push_front(value);
        } else if(index == this->size) {
            push_back(value);
        } else {
            Node *cur = head;
            for(int i = 0; i < index - 1; i++) {
                cur = cur->next;
            }
            newNode->next = cur->next;
            cur->next = newNode;
            this->size++;
        }
    }

    int get_element(int index) {
        if(index < 0 || index >= this->size) {
            return INT_MAX;
        }
        Node *cur = head;
        for(int i = 0; i < index; i++) {
            cur = cur->next;
        }
        return cur->value;
    }

    void delete_by_value(int value) {
        this->size--;
        Node *cur = head;
        while(cur->next->value != value) {
            cur = cur->next;
        }
        cur->next = cur->next->next;
    }

    void delete_by_index(int index) {
        if(index < 0 || index >= this->size) {
            cout << "Error.";
            return;
        } else if(index == 0) {
            head = head->next;
        } else if(index == this->size - 1) {
            Node *cur = head;
            for(int i = 0; i < index - 1; i++) {
                cur = cur->next;
            }
            cur->next = nullptr;
        } else {
            Node *cur = head;
            for(int i = 0; i < index - 1; i++) {
                cur = cur->next;
            }
            cur->next = cur->next->next;
        }
        this->size--;
    }

    void print() {
        Node *tmp = head;
        while(tmp) {
            cout << tmp->value << " ";
            tmp = tmp->next;
        }
        cout << "\n";
    }
};

int main() {
    LinkedList *ll = new LinkedList();
    LinkedList *ll1 = new LinkedList();
    LinkedList *ll2 = new LinkedList();
    for(int i = 1; i <= 5; i++) {
        ll->push_back(i);
        ll1->push_front(i);
        ll2->push_back(i);
    }
    cout << "Linked List 1: ";
    ll1->print();
    cout << "Linked List 2: ";
    ll2->print();

    ll->push_index(20, 0);
    ll->push_index(20, 6);
    ll->print();
    cout << ll->get_element(6) << "\n";
    ll->delete_by_value(5);
    ll->delete_by_index(0);
    ll->print();


    return 0;
}