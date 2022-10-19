#include <iostream>
#include <vector>

using namespace std;

string merge(string left, string right) {
    string result = "";
    int l = 0, r = 0;
    while(l < left.size() && r < right.size()) {
        if(left[l] < right[r]) {
            result += left[l];
            l++;
        } else {
            result += right[r];
            r++;
        }
    }
    while(l < left.size()) {
        result += left[l];
        l++;
    }
    while(r < right.size()) {
        result += right[r];
        r++;
    }
    return result;
}

string mergeSort(string s, int l, int r) {
    if(l == r) {
        string result = "";
        result += s[l];
        return result;
    }
    int mid = l + (r - l) / 2;
    string left = mergeSort(s, l, mid);
    string right = mergeSort(s, mid + 1, r);
    return merge(left, right);
}

int main() {
    int t;
    cin >> t;
    
    vector <string> v;
    string s;
    while(t--) {
        while(cin >> s) {
            v.push_back(mergeSort(s, 0, s.size() - 1));
        }
    }

    for(int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }

    return 0;
}