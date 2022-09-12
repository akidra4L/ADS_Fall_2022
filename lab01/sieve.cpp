#include <iostream>

using namespace std;

bool isPrime[10000];

void sieveFun(int x) {
    isPrime[0] = isPrime[1] = false;

    for(int i = 2; i <= x; i++) {
        isPrime[i] = true;
    }

    for(int i = 2; i <= x; i++) {
        if(isPrime[i]) {
            int j = i + i;
            while(j <= x) {
                isPrime[j] = false; 
                j += i;
            }
        }
    }

    for(int i = 0; i <= x; i++) {
        if(isPrime[i]) {
            cout << i << " ";
        }
    }
}

int main() {
    int n;
    cin >> n;

    sieveFun(n);

    return 0;
}