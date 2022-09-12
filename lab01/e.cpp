#include <iostream>
#include <deque>

using namespace std;

int main() {
    deque <int> b, n;
    for(int i = 0; i < 5; i++) {
        int x;
        cin >> x;
        b.push_back(x);
    }
    for(int i = 0; i < 5; i++) {
        int x;
        cin >> x;
        n.push_back(x);
    }

    int cnt = 0;
    int max = 1000000;
    while(!b.empty() && !n.empty() && cnt != max) {
        int boris = b.front();
        int nursik = n.front();
        b.pop_front();
        n.pop_front();

        if(boris == 9 && nursik == 0) {
            n.push_back(boris);
            n.push_back(nursik);
        }
        else if(boris == 0 && nursik == 9) {
            b.push_back(boris);
            b.push_back(nursik);
        } 
        else if(boris > nursik) {
            b.push_back(boris);
            b.push_back(nursik);
        } else {
            n.push_back(boris);
            n.push_back(nursik);
        }
        cnt++;
    }

    if(!b.empty()) {
        cout << "Boris " << cnt << endl;
    }
    else if(!n.empty()) {
        cout << "Nursik " << cnt << endl;
    } else {
        cout << "blin nichya" << endl;
    }

    return 0;
}