#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool isPrime[1000001];

vector <int> sieve() {
    isPrime[0] = isPrime[1] = false;

    for(int i = 2; i <= 1000001; i++) {
        isPrime[i] = true;
    }

    for(int i = 2; i * i <= 1000001; i++) {
        if(isPrime[i]) {
            int j = i + i;
            while(j <= 1000001) {
                isPrime[j] = false;
                j += i;
            }
        }
    }

    vector <int> arr;
    for(int i = 0; i <= 1000001; i++) {
        if(isPrime[i]) {
            arr.push_back(i);
        }
    }
    return arr;
}

bool isPrimeN(int n) {
    if(n == 0 || n == 1) {
        return false;
    }
    for(int i = 2; i * i < n; i++) {
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
        return 0;
    }
    if(isPrimeN(n)) {
        cout << 1 << "\n";
        return 0;
    }

    vector <int> v = sieve();
    int cnt = 0;
    for(int i = 0; i < v.size(); i++) {
        if(n > v[i] && n % v[i] == 0) {
            cnt++;
        }
    }
    cout << cnt << "\n";

    return 0;
}