#include <iostream>
#include <deque>

using namespace std;

int main() {
    int n; cin >> n;
    deque <int> d;
    while(n--) {
        int x; cin >> x;
        d.push_back(x);
        if(x >= 3000) {
            while(!d.empty() && d.front() < x - 3000) {
                d.pop_front();
            }
        }
        cout << d.size() << " ";
    }
    cout << "\n";

    return 0;
}