#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    vector<int> a(n);
    for (int& i : a) cin >> i;
    vector<int> res;
    int cnt = 0;
    for (int i = 0; i < n-1; ++i) {
        res.push_back(a[i]);
        if (gcd(a[i],a[i+1]) != 1) {
            cnt++;
            res.push_back(1);
        }
    }
    res.push_back(a[n-1]);
    cout << cnt << '\n';
    for (const auto& x : res) cout << x << ' ';
    cout << '\n';
}
