#include <iostream>

using namespace std;

const int N = 2 * 1e5 + 5;
int n, k;
int sheeps[N][4];
    
bool check(int x) {
    int counter = 0;
    for(int i = 0; i < n; i++) {
        if(sheeps[i][2] <= x && sheeps[i][3] <= x) {
            counter++;
        }
    }
    return counter >= k;
}

int main() {
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        cin >> sheeps[i][0] >> sheeps[i][1] >> sheeps[i][2] >> sheeps[i][3];
    }
    
    int l = 0, r = (int)1e9;
    while(r - l > 1) {
        int m = l + (r - l) / 2;
        if(check(m)) {
            r = m;
        } else {
            l = m;
        }
    }
    cout << r;

    return 0;
}