#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (int& i : a) cin >> i;
    for (int i = 0; i < n; i++) {
        int x = a[i];
        int y = -1;
        for (int j = 0; j < n; j++) {
            if (i==j) continue;
            if (y==-1) y = a[j];
            else y = gcd(y,a[j]);
        }
        if (x!=y) {
            cout << "YES\n";
            for (int k = 0; k < n; k++) {
                if (k==i) cout << 1 << " ";
                else cout << 2 << " ";
            }
            cout << "\n";
            return;
        }
    }
    cout << "NO\n";
}

int main() {
    int t; cin >> t;
    while (t--) solve();
    return 0;
}