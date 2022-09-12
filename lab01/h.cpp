#include <iostream>

using namespace std;

void solve(int n) {
    if(n == 0 || n == 1) {
        cout << "NO" << endl;
        return;
    }
    for(int i = 2; i*i <= n; i++) {
        if(n % i == 0) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(0);

    int n;
    cin >> n;

    solve(n);

    return 0;
}