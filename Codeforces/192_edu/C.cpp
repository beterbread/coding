#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n,k; cin >> n >> k;
        unordered_map<int,int> map;
        for (int i = 0; i < n; ++i) {
            int x; cin >> x;
            map[x]++;
        }

        vector<int> joe;
        for (const auto& x : map) joe.push_back(x.second);
        sort(joe.begin(),joe.end());
        vector<int> pre(joe.size());
        pre[0] = joe[0];
        for (int i = 1; i < joe.size(); ++i) pre[i] = joe[i] + pre[i-1];

        // debug
        // for (const int& i : joe) cout << i << ' ';
        // cout << '\n';
        // for (const int& i : pre) cout << i << ' ';
        // cout << '\n';

        auto query = [&](int x) -> pair<int,int> {
            int l = 0, r = joe.size()-1;
            while (l < r) {
                int mid = l+(r-l)/2;
                if (joe[mid] > x) {
                    r = mid;
                }
                else {
                    l = mid+1;
                }
            }
            int total = pre[joe.size()-1];
            if (l > 0) total -= pre[l-1];
            int mult = joe.size() - l;
            total -= (mult * x);
            return {total,mult} ; // total, distinct
        };
        
        unordered_set<int> set; // used
        int res = 0;
        for (int i = 0; i < joe[joe.size()-1]; ++i) {
            auto [total,mult] = query(i);
            if (total == k) {
                if (set.find(mult) == set.end()) {
                    res++;
                    set.insert(mult);
                }
            }
            else if (total < k && (k - total) % mult == 0) {
                if (set.find(mult) == set.end()) {
                    res++;
                    set.insert(mult);
                }
            }
        }
        cout << res << '\n';
    }
}
