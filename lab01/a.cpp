#include <iostream>
#include <deque>

using namespace std;

void solve() {
    int x;
    cin >> x;
    deque <int> d;
    
    for(int i = x; i >= 1; i--) {
        d.push_back(i);
        for(int j = 0; j <= i; j++) {
            d.push_front(d.back());
            d.pop_back();
        }
    }
    
    while(!d.empty()) {
        cout << d.front() << " ";
        d.pop_front();
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(0);

    int n;
    cin >> n;
    while(n--) {
        solve();
    }

    return 0;
}