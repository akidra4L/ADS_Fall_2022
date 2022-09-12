#include <iostream>
#include <vector>

using namespace std;

bool isPrime[100001];

bool isPrimeNumber(int n) {
    if(n == 0 || n == 1) {
        return false;
    }
    for(int i = 2; i*i <= n; i++) {
        if(n % i == 0) {
            return false;
        }
    }
    return true;
}

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
    for(int i = 2; i <= 100001; i++) {
        if(isPrime[i]) {
            v.push_back(i);
        }
    }
    
    vector <int> ans;
    for(int i = 0; i < v.size(); i++) {
        if(isPrimeNumber(i + 1)) {
            ans.push_back(v[i]);
        }
    }
    cout << ans[x - 1] << endl;
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(0);

    int n;
    cin >> n;
    solve(n);

    return 0;
}