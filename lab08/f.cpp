#include <iostream>
#include <unordered_set>

using namespace std;

int main() {
    string s; cin >> s;

    unordered_set<string> us;
    for(int i = 0; i < s.size(); i++) {
        string str = "";
        for(int j = i; j < s.size(); j++) {
            str += s[j];
            us.insert(str);
        }
    }
    cout << us.size() << "\n";

    return 0;
}