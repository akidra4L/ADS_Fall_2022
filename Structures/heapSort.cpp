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
        heap.push_back(value);
        int i = heap.size() - 1;
        while(i != 0 && heap[parent(i)] > heap[i]) {
            swap(heap[parent(i)], heap[i]);
            i = parent(i);
        } 
    }

    int extractMin() {
        if(heap.size() == 1) {
            int root = heap[0];
            heap.pop_back();
            return root;
        }
        int root = heap[0];
        heap[0] = heap[heap.size() - 1];
        heap.pop_back();
        heapify(0);
        return root;
    }

    void heapify(int i) {
        int l = left(i);
        int r = right(i);
        int smallest = i;
        if(l < heap.size() && heap[l] < heap[smallest]) {
            smallest = l;
        }
        if(r < heap.size() && heap[r] < heap[smallest]) {
            smallest = r;
        }
        if(smallest != i) {
            swap(heap[smallest], heap[i]);
            heapify(smallest);
        }
    }

    int getSize() {
        return heap.size();
    }
};

int main() {
    MinHeap *heap = new MinHeap();

    int n; cin >> n;
    int arr[n];

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        heap->insert(arr[i]);
    }

    while(heap->getSize() > 0) {
        cout << heap->extractMin() << " ";
    }
    cout << "\n";

    return 0;
}