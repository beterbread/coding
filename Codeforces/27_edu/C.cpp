#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    map<int,int> map;
    while (n--) {
        int l,r; cin >> l >> r;
        map[l]++;
        map[r+1]--;
    }
    int joe = 0;
    bool ok = true;
    for (const auto& x : map) {
        joe += x.second;
        if (joe > 2) {
            ok = false;
            break;
        }
    }
    cout << (ok ? "YES" : "NO") << '\n';
    return 0;
}