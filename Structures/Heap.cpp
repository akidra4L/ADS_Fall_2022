#include <iostream>
#include <vector>

using namespace std;

struct MinHeap {
    vector <int> heap;

    int parent(int i) {
        return (i - 1) / 2;
    }

    int left(int i) {
        return 2 * i + 1;
    }

    int right(int i) {
        return 2 * i + 2;
    }

    void insert(int value) {
        this->heap.push_back(value);
        int i = this->heap.size() - 1;
        while(i != 0 && this->heap[parent(i)] < this->heap[i]) {
            swap(this->heap[parent(i)], this->heap[i]);
            i = parent(i);
        }
    }

    void print() {
        for(int i = 0; i < heap.size(); i++) {
            cout << heap[i] << " ";
        }
        cout << "\n";
    }
};

int main() {
    MinHeap *mh = new MinHeap();

    for(int i = 8; i >= 0; i--) {
        mh->insert(i);
    }
    mh->print();

    return 0;
}