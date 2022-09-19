#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool myComp(pair <int, int> &p1, pair <int, int> &p2) {
    return p1.first > p2.first;
}

int main() {
    int n;
    cin >> n;
    vector <int> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }

    map <int, int> m;
    for(int i = 0; i < n; i++) {
        m[v[i]] += 1;
    }

    map <int, int> :: iterator it;
    vector <pair <int, int> > arr;
    int max = -1e9;
    for(it = m.begin(); it != m.end(); it++) {
        if(max < (*it).second) {
            max = (*it).second;
        }
        arr.push_back(make_pair((*it).first, (*it).second));
    }

    sort(arr.begin(), arr.end(), myComp);
    vector <pair <int, int> > :: iterator it2;
    for(it2 = arr.begin(); it2 != arr.end(); it2++) {
        if(it2->second == max) {
            cout << it2->first << " ";
        }
    }

    return 0;
}