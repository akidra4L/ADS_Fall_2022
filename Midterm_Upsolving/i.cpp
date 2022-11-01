#include <iostream>
#include <stack>

using namespace std;

string s = "";
string toBin(long long n) {
    if(n == 0) {
        return s;
    }
    s = char((n % 2) + 48) + s;
    return toBin(n / 2);
}

bool solve(string s) {
    stack <char> st;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == '1') {
            st.push(s[i]);
        } else {
            if(st.empty()) {
                return false;
            } else {
                st.pop();
            }
        }
    }
    return st.empty();
}

int main() {
    int q; cin >> q;
    while(q--) {
        long long x; cin >> x;
        s = "";
        if(solve(toBin(x))) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}