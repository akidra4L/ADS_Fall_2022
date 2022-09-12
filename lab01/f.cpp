#include <iostream>
#include <vector>

using namespace std;

bool isPrime[100001];

void solve(int x) {
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

    vector <int> v;
    for(int i = 0; i <= 100001; i++) {
        if(isPrime[i]) {
            v.push_back(i);
        }
    }
    cout << v[x - 1] << endl;
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(0);

    int n;
    cin >> n;
    solve(n);

    return 0;
}