#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n,q; cin >> n >> q;
        string s; cin >> s;
        vector<int> pre(n);
        for (int i = 0; i < n-1; ++i) {
            if (s[i] == s[i+1]) {
                pre[i+1] = 1;
            }
        }
        for (int i = 1; i < n; ++i) pre[i] += pre[i-1];
        while (q--) {
            int l,r,k; cin >> l >> r >> k;
            l--; r--;
            int joe = pre[r] - (l > 0 ? pre[l-1] : 0);
            if (l > 0 && s[l-1] == s[l]) joe--;
            int ops = ceil(double(joe) / 2);
            if (ops <= k) {
                cout << "YES\n";
            }
            else {
                cout << "NO\n";
            }
        }
    }
}