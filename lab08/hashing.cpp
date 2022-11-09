#include <iostream>

using namespace std;

const int p = 31;
const int q = 1e9 + 5;

int main() {
    string s; cin >> s;
    long long hash = 0, power = 1;
    for(int i = 0; i < s.size(); i++) {
        hash += ((s[i] - 'a' + 1) * power) % q;
        power *= p;
    }
    cout << hash << "\n";

    return 0;
}