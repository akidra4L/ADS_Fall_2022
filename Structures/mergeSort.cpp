#include <iostream>
#include <vector>

using namespace std;

vector <int> merge(vector <int> left, vector <int> right) {
    vector <int> result;
    int l = 0, r = 0;
    while(l < left.size() && r < right.size()) {
        if(left[l] < right[r]) {
            result.push_back(left[l]);
            l++;
        } else {
            result.push_back(right[r]);
            r++;
        }
    }
    while(l < left.size()) {
        result.push_back(left[l]);
        l++;
    }
    while(r < right.size()) {
        result.push_back(right[r]);
        r++;
    }
    return result;
}

vector <int> mergeSort(vector <int> v, int l, int r) {
    if(l == r) {
        vector <int> result;
        result.push_back(v[l]);
        return result;
    }
    int mid = l + (r - l) / 2;
    vector <int> left = mergeSort(v, l, mid);
    vector <int> right = mergeSort(v, mid + 1, r);
    return merge(left, right);
}

int main() {
    int n; cin >> n;
    vector <int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    arr = mergeSort(arr, 0, arr.size() - 1);

    for(int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }

    return 0;
}