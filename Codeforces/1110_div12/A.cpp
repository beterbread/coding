#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n,k; cin >> n >> k;
        string s; cin >> s;
        if (k > n/2) {
            cout << -1 << '\n';
            continue;
        }
        else {
            int res = 0;
            for (int i = 0; i < k; ++i) {
                res += s[i] == 'L';
            }
            for (int i = n-1; i >= n-k; --i) {
                res += s[i] == 'R';
            }
            cout << res << '\n';
        }
    }
}