#include <iostream>
#include <vector>

using namespace std;

bool isPrime[100001];

vector <int> sieve(int x) {
    isPrime[0] = isPrime[1] = false;

    for(int i = 2; i <= x; i++) {
        isPrime[i] = true;
    }

    for(int i = 2; i * i <= x; i++) {
        if(isPrime[i]) {
            int j = i + i;
            while(j <= x) {
                isPrime[j] = false;
                j += i;
            }
        }
    }

    vector <int> arr;
    for(int i = 0; i <= x; i++) {
        if(isPrime[i]) {
            arr.push_back(i);
        }
    }
    return arr;
}

int main() {
    int n; cin >> n;

    vector <int> arr = sieve(n);

    int l = 0, r = arr.size() - 1;
    int ansL = 0, ansR = 0;
    while(l < r) {
        int sum = arr[l] + arr[r];
        if(sum == n) {
            ansL = arr[l];
            ansR = arr[r];
            break;
        } else if(sum < n) {
            l++;
        } else {
            r--;
        }
    }
    cout << ansL << " " << ansR << "\n";

    return 0;
}