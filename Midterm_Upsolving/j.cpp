#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int m; cin >> m;
    int n; cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a, a + n);

    int l = 0, r = n - 1;
    int arr[2];
    while(l < r) {
        int sum = a[l] + a[r];
        if(sum == m) {
            arr[0] = a[l];
            arr[1] = a[r];
            break;
        } else if(sum > m) {
            r--;
        } else {
            l++;
        }
    }

    cout << arr[0] << " " << arr[1] << "\n";

    return 0;
}