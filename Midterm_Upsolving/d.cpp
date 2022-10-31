#include <iostream>

using namespace std;

bool isPrime(int n) {
    if(n == 0 || n == 1) {
        return false;
    }
    for(int i = 2; i * i <= n; i++) {
        if(n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int n; cin >> n;
    if(n == 0 || n == 1) {
        cout << 0 << "\n";
    } else if(isPrime(n)) {
        cout << 1 << "\n";
    } else {
        int i = 2, cnt = 0;
        bool flag = false;
        while(n > 1) {
            if(n % i == 0) {
                if(!flag) {
                    cnt++;
                }
                flag = true;
                n /= i;
            } else {
                i++;
                flag = false;
            }
        }
        cout << cnt << "\n";
    }

    return 0;
}