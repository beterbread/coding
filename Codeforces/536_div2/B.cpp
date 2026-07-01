#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n,m; cin >> n >> m;
    vector<long long> a(n),c(n);
    for (long long& i : a) cin >> i;
    for (long long& i : c) cin >> i;
    priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> pq;
    for (int i = 0; i < n; i++) pq.push({c[i],i});
    auto query = [&](int t, long long d) -> void {
        t--; // zero indexing
        long long res = 0;
        long long mn = min(a[t],d);
        a[t] -= mn;
        d -= mn;
        res += (mn * c[t]);
        while (!pq.empty() && d > 0) {
            auto [cost,idx] = pq.top(); pq.pop();
            if (a[idx] == 0) continue;
            mn = min(a[idx],d);
            a[idx] -= mn;
            d -= mn;
            res += (mn * cost);
            if (d == 0 && a[idx] > 0) {
                pq.push({cost,idx});
            }
        }
        cout << (d == 0 ? res : 0) << '\n';
    };
    while (m--) {
        int t,d; cin >> t >> d;
        query(t,d);
    }
}