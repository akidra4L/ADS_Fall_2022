#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int m, n;
struct Edge {
    int from, to, cost;
    Edge(int from, int to, int cost) {
        this->from = from;
        this->to = to;
        this->cost = cost;
    }
};
vector <Edge> e;

int fordBellman(int s, int f) {
	vector<int> d(n + 1, 1e9);
	d[s] = 0;
	while (true) {
		bool hasChanged = false;
		for (int j = 0; j < m; j++) {
			if (d[e[j].to] > d[e[j].from] + e[j].cost) {
				d[e[j].to] = d[e[j].from] + e[j].cost;
				hasChanged = true;
			}
		}
		if (!hasChanged) break;
	}
	return d[f];
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		e.push_back(Edge(u, v, w));
	}
    int s, a, b, f;
	cin >> s >> a >> b >> f;

	int sa = fordBellman(s, a);
	int sb = fordBellman(s, b);
	int ab = fordBellman(a, b);
	int ba = fordBellman(b, a);
	int af = fordBellman(a, f);
	int bf = fordBellman(b, f);

	if (sa + ab + bf >= 1e9 && sb + ba + af >= 1e9) {
		cout << "-1\n";
	} else {
		cout << min(sa + ab + bf, sb + ba + af) << "\n";
	}

	return 0;
}