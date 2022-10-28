#include <iostream>
#include <algorithm>
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
        heap.push_back(value);
        int i = heap.size() - 1;
        while(i != 0 && heap[parent(i)] > heap[i]) {
            swap(heap[parent(i)], heap[i]);
            i = parent(i);
        }
    }

    int extractMin() {
        if(heap.size() == 0) return INT_MAX;
        if(heap.size() == 1) {
            int root = heap[0];
            heap.pop_back();
            return root;
        }
        int root = heap[0];
        heap[0] = heap[heap.size() - 1];
        heap.pop_back();
        heapify_down(0);
        return root;
    }

    void heapify_up(int i) {
        while(i != 1 && heap[i] < heap[parent(i)]) {
            swap(heap[i], heap[parent(i)]);
            heapify_up(parent(i));
        }
    }

    void heapify_down(int i) {
        int l = left(i);
        int r = right(i);
        int smallest = i;
        while(l < heap.size() && heap[l] < heap[smallest]) {
            smallest = l;
        }
        while(r < heap.size() && heap[r] < heap[smallest]) {
            smallest = r;
        }
        if(smallest != i) {
            swap(heap[smallest], heap[i]);
            heapify_down(smallest);
        }
    }

    void update(int i, int value) {
        heap[i] += value;
        if(heap[i] > heap[parent(i)]) {
            heapify_down(i);
        } else {
            heapify_up(i);
        }
    }

    void print() {
        for(int i = 0; i < heap.size(); i++) {
            cout << heap[i] << " ";
        }
        cout << "\n";
    }

    int get_size() {
        return heap.size();
    }

    bool isEmpty() {
        return heap.size() == 0;
    }
};

int main() {
    MinHeap *mh = new MinHeap();

    int n; cin >> n;
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        mh->insert(x);
    }
    mh->print();

    int t; cin >> t;
    while(t--) {
        int i, value;
        cin >> i >> value;
        mh->update(i, value);
        mh->print();
    }

    while(!mh->isEmpty()) {
        cout << mh->extractMin() << " ";
    }
    cout << "\n";

    return 0;
}