#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

vector <pair <int, int> > g;
vector <int> p;

int dsuGet(int v) {
	if (v == p[v]) {
		return v;
	}
	return p[v] = dsuGet(p[v]);
}

void dsuUnite(int a, int b) {
	a = dsuGet(a);
	b = dsuGet(b);
	if (a != b) {
        p[a] = b;
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    p.resize(n);

    for(int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        a--; b--;
        g.push_back(make_pair(a, b));
    }

    for(int i = 0; i < n; i++) {
        p[i] = i;
    }

    for(int i = 0; i < g.size(); i++) {
        int a = g[i].first, b = g[i].second;
        if(dsuGet(a) != dsuGet(b)) {
            dsuUnite(a, b);
        }
    }

    unordered_set <int> s;
    vector <int> res;
    int cnt = 0;
    for(int i = n - 1; i >= 0; i--) {
        res.push_back(cnt);
        int x = dsuGet(i);
        if(s.find(x) == s.end()) {
            cnt++;
        }
        s.insert(x);
    }

    reverse(res.begin(), res.end());
    for(int i = 0; i < res.size(); i++) {
        cout << res[i] << "\n";
    }

    return 0;
}