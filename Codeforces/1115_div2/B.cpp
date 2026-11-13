#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    int z = 0, o = 0;
    for (int i = 0; i < n-1; ++i) {
        if (s[i] == s[i+1]) {
            z += s[i] == '0';
            o += s[i] == '1';
        }
    }
    if (z < o-1) {
        if (s[0] == '0') z++;
        if (z < o-1) {
            if (0 != n-1 && s[n-1] == '0') z++;
        }
    }
    else if (o < z-1) {
        if (s[0] == '1') o++;
        if (o < z-1) {
            if (0 != n-1 && s[n-1] == '1') o++;
        }
    }
    if (abs(z-o) <= 1) {
        cout << z+o << '\n';
    }
    else {
        cout << -1 << '\n';
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        solve();
    }
}