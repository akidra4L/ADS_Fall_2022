#include <iostream>
#include <vector>

using namespace std;

const int p = 31;

int main() {
    string s; cin >> s;
    vector <long long> power(s.size());
    power[0] = 1;
    for(int i = 1; i < s.size(); i++) {
        power[i] = power[i - 1] * p;
    }

    // int q; cin >> q;
    // while(q--) {
    //     int l, r;
    //     cin >> l >> r;
    // }

    return 0;
}