#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int k; cin >> k;
        int x = 0, y = 0;
        while (k--) {
            int c; cin >> c;
            if (c >= 2) x++;
            if (c >= 3) y++;
        }
        cout << (x >= 2 || y >= 1 ? "YES" : "NO") << '\n';
    }
}
