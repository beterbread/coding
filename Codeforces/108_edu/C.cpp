#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<ll> u(n),s(n);
        for (ll& i : u) cin >> i;
        for (ll& i : s) cin >> i;
        vector<vector<ll>> a(n);
        for (int i = 0; i < n; ++i) {
            a[u[i]-1].push_back(s[i]);
        }
        for (int i = 0; i < n; ++i) {
            sort(a[i].rbegin(),a[i].rend());
            for (int j = 1; j < a[i].size(); ++j) a[i][j] += a[i][j-1];
        }
        vector<ll> res(n,0);
        for (int i = 0; i < n; ++i) {
            int sz = a[i].size();
            for (int k = 1; k <= n; ++k) {
                if (k > sz) break;
                res[k-1] += a[i][sz-(sz%k)-1];
            }
        }
        for (int i = 0; i < n; i++) cout << res[i] << ' ';
        cout << '\n';
    }
}
