#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n,m,k; cin >> n >> m >> k;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) 
        cin >> a[i];
    vector<array<ll,3>> ops(m);
    for (int i = 0; i < m; ++i) 
        cin >> ops[i][0] >> ops[i][1] >> ops[i][2];
    vector<array<ll,2>> query(k);
    for (int i = 0; i < k; ++i) 
        cin >> query[i][0] >> query[i][1];

    vector<ll> diff(m,0);
    for (int i = 0; i < k; ++i) {
        const auto& [x,y] = query[i];
        diff[x-1]++;
        if (y < m) {
            diff[y]--;
        }
    }
    for (int i = 1; i < m; ++i) {
        diff[i] += diff[i-1];
    }
    vector<ll> res(n,0);
    for (int i = 0; i < m; ++i) {
        const auto& [l,r,d] = ops[i];
        ll val = d * diff[i];
        res[l-1] += val;
        if (r < n) {
            res[r] -= val;
        }
    }
    cout << (a[0]+res[0]) << ' ';
    for (int i = 1; i < n; ++i) {
        res[i] += res[i-1];
        cout << (a[i]+res[i]) << ' ';
    }
    cout << '\n';
}