#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int partition(int arr[], int l, int r) {
    int pivot = arr[r];
    int pIndex = l;
    for(int i = l; i < r; i++) {
        if(arr[i] < pivot) {
            swap(arr[pIndex], arr[i]);
            pIndex++;
        }
    }
    swap(arr[pIndex], arr[r]);
    return pIndex;
}

void quickSort(int arr[], int l, int r) {
    if(l < r) {
        int p = partition(arr, l, r);
        quickSort(arr, l, p - 1);
        quickSort(arr, p + 1, r);
    }
}

int main() {
    int n; cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    quickSort(arr, 0, n - 1);

    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}