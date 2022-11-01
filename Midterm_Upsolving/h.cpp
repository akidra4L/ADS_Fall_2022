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

    int solve() {
        int cnt = 0;
        int i = 0;
        int l = left(i);
        int r = right(i);
        while(l < heap.size() && r < heap.size()) {
            if(heap[l] < heap[r]) {
                cnt++;
            }
            i++;
            l = left(i);
            r = right(i);
        }
        return cnt;
    }
};

int main() {
    MaxHeap *heap = new MaxHeap();

    int n; cin >> n;
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        heap->insert(x);
    }
    cout << heap->solve() << "\n";

    return 0;
}