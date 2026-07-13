#include <bits/stdc++.h>
using namespace std;

void solve() {
    int x; cin >> x;
    int res = 0;
    for (int i = 1; i * i <= x; ++i) {
        if (x % i == 0) {
            if (i * i == x) {
                res++;
            }
            else {
                res += 2;
            }
        }
    }
    cout << res << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    while (n--) solve();
    return 0;
}