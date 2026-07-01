#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        long long y,x; cin >> y >> x;
        long long mx = max(y,x), mn = min(y,x);
        long long res = 0;
        if (mx&1) {
            if (y==mx) res = (mx-1)*(mx-1)+x;
            else res = mx*mx - mn + 1;
        }
        else {
            if (x==mx) res = (mx-1)*(mx-1)+y;
            else res = mx*mx - mn + 1;
        }
        cout << res << '\n';
    }
    return 0;
}