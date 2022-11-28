#include <iostream>
#include <vector>

using namespace std;

vector <pair <int, pair <int, int> > > g;
vector<int> p;

int dsuGet(int v) {
	if (v == p[v]) {
		return v;
	}
	return p[v] = dsu_get(p[v]);
}

void dsuUnite(int a, int b) {
	a = dsu_get(a);
	b = dsu_get(b);
	if (a != b) {
        p[a] = b;
    }
}

int main() {
    int n, q;
    cin >> n >> q;
    p.resize(n);

    while(q--) {
        int l, r, cost;
        cin >> l >> r >> cost;
        for(int i = l; i < r; i++) {
            for(int j = i + 1; j <= r; j++) {
                if(i != j) {
                    g.push_back(make_pair(cost, make_pair(i, j)));
                }
            }
        }
    }

    return 0;
}