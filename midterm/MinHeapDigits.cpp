#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int getSum(int n) {
    int total = 0;
    while(n > 0) {
        total += (n % 10);
        n /= 10;
    }
    return total;
}

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
        while(i != 0 && getSum(heap[parent(i)]) > getSum(heap[i])) {
            swap(heap[parent(i)], heap[i]);
            i = parent(i);
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

    void heapify_down(int i) {
        int l = left(i);
        int r = right(i);
        int smallest = i;
        while(l < heap.size() && getSum(heap[l]) < getSum(heap[smallest])) {
            smallest = l;
        }
        while(r < heap.size() && getSum(heap[r]) < getSum(heap[smallest])) {
            smallest = r;
        }
        if(smallest != i) {
            swap(heap[smallest], heap[i]);
            heapify_down(smallest);
        }
    }

    void heapify_up(int i) {
        while(i != 0 &&  getSum(heap[parent(i)]) > getSum(heap[i])) {
            swap(heap[parent(i)], heap[i]);
            heapify_up(parent(i));
        }
    }

    bool isEmpty() {
        return heap.size() == 0;
    }
};

int main() {
    MinHeap *heap = new MinHeap();

    int n; cin >> n;
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        heap->insert(x);
    }

    while(!heap->isEmpty()) {
        cout << heap->extract_min() << " ";
    }
    cout << "\n";

    return 0;
}