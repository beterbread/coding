#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n,q; cin >> n >> q;
        vector<long long> a(n);
        for (auto& i : a) cin >> i;
        vector<long long> pre(n);
        pre[0] = a[0];
        for (int i = 1; i < n; ++i) pre[i] = a[i] + pre[i-1];
        vector<int> b(n);
        map<int,int> map;
        for (int i = 0; i < n; ++i) {
            b[i] = a[i];
            if (i>0 && b[i] < b[i-1]) b[i] = b[i-1];
            if (map.find(a[i]) == map.end()) map[a[i]] = i;
        }
        auto query = [&](int q) -> long long {
            auto it = upper_bound(b.begin(),b.end(),q);
            if (it == b.end()) return pre[n-1];
            if (it == b.begin()) return 0LL;
            int pos = map[*it];
            return pos==0 ? 0 : pre[pos-1];
        };
        while (q--) {
            int joe; cin >> joe;
            cout << query(joe) << ' ';
        }
        cout << '\n';
    }
}
