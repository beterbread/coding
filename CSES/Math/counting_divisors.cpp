#include <bits/stdc++.h>
using namespace std;

void solve() {
    int x; cin >> x;
    cout << factor(x) << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    while (n--) solve();
    return 0;
}