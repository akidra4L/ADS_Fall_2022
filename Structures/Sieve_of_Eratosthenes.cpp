#include <iostream>
#include <vector>

using namespace std;

bool isPrime[100001];

vector <int> sieve() {
    isPrime[0] = isPrime[1] = false;

    for(int i = 2; i <= 100001; i++) {
        isPrime[i] = true;
    }

    for(int i = 2; i <= 100001; i++) {
        if(isPrime[i]) {
            int j = i + i;
            while(j <= 100001) {
                isPrime[j] = false;
                j += i;
            }
        }
    }

    vector <int> arr;
    for(int i = 0; i < 100001; i++) {
        if(isPrime[i]) {
            arr.push_back(i);
        }
    }
    return arr;
}

int main() {
    vector <int> arr = sieve();
    
    for(int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }

    return 0;
}