#include <iostream>
#include <stack>

using namespace std;

bool solve(string s) {
    stack <char> st;

    for(int i = 0; i < s.size(); i++) {
        if(!st.empty() && st.top() == s[i]) {
            st.pop();
        } else {
            st.push(s[i]);
        }
    }

    return st.empty();
}

int main() {
    string s;
    cin >> s;

    if(solve(s)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}