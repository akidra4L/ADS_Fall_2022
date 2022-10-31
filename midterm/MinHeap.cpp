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
        heapify_up(i);
    }

    void heapify_up(int i) {
        while(i != 0 && heap[parent(i)] > heap[i]) {
            swap(heap[parent(i)], heap[i]);
            i = parent(i);
        }
    }

    void heapify_down(int i) {
        int l = left(i);
        int r = right(i);
        int smallest = i;
        while(l < heap.size() && heap[l] < heap[smallest]) {
            smallest = l;
        }
        while (r < heap.size() && heap[r] < heap[smallest]) {
            smallest = r;
        }
        if(smallest != i) {
            swap(heap[smallest], heap[i]);
            heapify_down(smallest);
        }
    }

    int extract_min() {
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

    bool isEmpty() {
        return heap.size() == 0;
    }
};

int main() {
    MinHeap *heap = new MinHeap();

    for(int i = 1; i <= 5; i++) {
        heap->insert(i);
    }

    while(!heap->isEmpty()) {
        cout << heap->extract_min() << " ";
    }
    cout << "\n";

    return 0;
}