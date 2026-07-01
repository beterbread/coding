#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n,k; cin >> n >> k;
        vector<int> a(n);
        for (int& i : a) cin >> i;
        vector<vector<int>> pos(k,{0});
        for (int i = 0; i < n; ++i) {
            pos[a[i]-1].push_back(i+1);
        }
        int res = INT_MAX;
        for (int i = 0; i < k; ++i) {
            pos[i].push_back(n+1);
            multiset<int> set;
            for (int j = 0; j < pos[i].size()-1; ++j) {
                int dist = pos[i][j+1] - pos[i][j] - 1;
                set.insert(dist);
            }
            int mx = *prev(set.end());
            if (mx == 1) {
                set.insert(0);
            }
            else if (mx&1) {
                set.insert((mx-1)/2);
                set.insert((mx-1)/2);
            }
            else {
                set.insert(floor(double(mx)/2.0));
                set.insert(ceil(double(mx)/2.0));
            }
            set.erase(set.find(mx));
            res = min(res,*prev(set.end()));
        }
        cout << res << '\n';
    }
}
