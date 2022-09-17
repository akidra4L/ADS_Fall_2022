#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int n, k;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cin >> k;

    vector <int> diff;
    for(int i = 0; i < n; i++) {
        diff.push_back(abs(k - a[i]));
    }

    int min = (int)1e9, index = 0;
    for(int i = 0; i < diff.size(); i++) {
        if(min > diff[i]) {
            min = diff[i];
            index = i;
        }
    }
    cout << index;

    return 0;
}