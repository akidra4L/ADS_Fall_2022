#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct MaxHeap {
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
        while(i != 0 && heap[parent(i)] < heap[i]) {
            swap(heap[parent(i)], heap[i]);
            i = parent(i);
        }
    }

    int extractMax() {
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

    void update(int i, int value) {
        heap[i] += value;
        int x = heap[i];
        heapify_up(i);
        cout << get_index(x) << "\n";
    }

    int get_index(int value) {
        for(int i = 0; i < heap.size(); i++) {
            if(heap[i] == value) {
                return i + 1;
            }
        }
        return -1;
    }

    void heapify_up(int i) {
        while(i != 0 && heap[parent(i)] < heap[i]) {
            swap(heap[parent(i)], heap[i]);
            heapify_up(parent(i));
        }
    }

    void heapify_down(int i) {
        int l = left(i);
        int r = right(i);
        int greatest = i;
        while(l < heap.size() && heap[l] > heap[greatest]) {
            greatest = l;
        }
        while(r < heap.size() && heap[r] > heap[greatest]) {
            greatest = r;
        }
        if(greatest != i) {
            swap(heap[greatest], heap[i]);
            heapify_down(greatest);
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
    MaxHeap *heap = new MaxHeap();

    int n; cin >> n;
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        heap->insert(x);
    }
    int q; cin >> q;
    while(q--) {
        int idx, val;
        cin >> idx >> val;
        heap->update(idx - 1, val);
    }
    heap->print();

    return 0;
}