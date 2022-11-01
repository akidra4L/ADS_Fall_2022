#include <iostream>
#include <deque>

using namespace std;

int main() {
    deque <int> d;

    int q; cin >> q;
    int cnt = 0;
    while(q--) {
        int command; cin >> command;
        if(command == 1) {
            int x; cin >> x;
            if(cnt % 2 == 0) {
                d.push_back(x);
            } else {
                d.push_front(x);
            }
        } else {
            cnt++;
        }
    }

    if(cnt % 2 == 0) {
        while(!d.empty()) {
            cout << d.front() << " ";
            d.pop_front();
        } 
    } else {
        while(!d.empty()) {
            cout << d.back() << " ";
            d.pop_back();
        }
    }
    cout << "\n";

    return 0;
}