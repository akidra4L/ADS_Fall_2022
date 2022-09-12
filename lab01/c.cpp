#include <iostream>
#include <stack>

using namespace std;

string solve(string s) {
    stack <char> st;

    for(int i = 0; i < s.size(); i++) {
        if(s[i] >= 'a' && s[i] <= 'z') {
            st.push(s[i]);
        }
        else if(s[i] == '#') {
            st.pop();
        }
    }
    
    string ans = "";
    while(!st.empty()) {
        ans += st.top();
        st.pop();
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(0);

    string s1, s2;
    cin >> s1 >> s2;

    if(solve(s1) == solve(s2)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}