#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <int> searchRange(vector <int>& v, int target) {
    vector <int> ans;
    int first = -1;
    int l = 0, r = v.size() - 1;
    while(l <= r) {
        int mid = l + (r - l) / 2;
        if(v[mid] == target) {
            first = mid;
            r = mid - 1;
        } 
        if(v[mid] < target) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    if(first == -1) {
        ans.push_back(-1);
        ans.push_back(-1);
        return ans;
    }

    int second = -1;
    l = first, r = v.size() - 1;
    while(l <= r) {
        int mid = l + (r - l) / 2;
        if(v[mid] == target) {
            second = mid;
            l = mid + 1;
        }
        if(v[mid] < target) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    ans.push_back(first);
    ans.push_back(second);
    return ans;
}

int main() {
    int n; cin >> n;
    vector <int> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    int x; cin >> x;

    vector <int> ans = searchRange(v, x);
    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << "\n";

    return 0;
}