#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int main() {
	int n; cin >> n;
	int d[n][n];
	set <int> toIgnore; 
	for (int i = 0; i < n; i++) {
		toIgnore.insert(i); 
		for (int j = 0; j < n; j++) {
			cin >> d[i][j];
		}
	}
	
	for (int q = 0; q < n; q++) {
        int x; cin >> x;
		x--;
		toIgnore.erase(x);
		int ans = 0;
		for (int k = 0; k < n; k++) {
			for (int i = 0; i < n; i++) {
				if (toIgnore.find(i) != toIgnore.end()) {
                    continue;
                }
				for (int j = 0; j < n; j++) {
					if (toIgnore.find(j) != toIgnore.end()) {
                        continue;
                    }
					if (d[i][j] > d[i][k] + d[k][j]) {
						d[i][j] = d[i][k] + d[k][j];
					}
				}
			}
		}
		for (int i = 0; i < n; i++) {
			if (toIgnore.find(i) != toIgnore.end()) {
                continue;
            }
			for (int j = 0; j < n; j++) {
				if (toIgnore.find(j) != toIgnore.end()) {
                    continue;
                }
				ans = max(ans, d[i][j]);
			}
		}
		cout << ans << "\n";
	}

	return 0;
}