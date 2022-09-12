#include <iostream>
#include <queue>

using namespace std;

int main() {
    int n;
    string str;
    cin >> n >> str;

    queue <int> k, s;
    for(int i = 0; i < str.size(); i++) {
        if(str[i] == 'K') {
            k.push(i);  
        } else {
            s.push(i);
        }
    }

    while(!k.empty() && !s.empty()) {
        int kat = k.front();
        int sak = s.front();
        k.pop();
        s.pop();

        if(kat < sak) {
            k.push(kat + n);
        } else {
            s.push(sak + n);
        }
    }

    if(!k.empty()) {
        cout << "KATSURAGI" << endl;
    } else {
        cout << "SAKAYANAGI" << endl;
    }

    return 0;
}