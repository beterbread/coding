#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    vector<int> a(n);
    for (int& i : a) cin >> i;
    long long res = 0;
    for (int i = 1; i < n; i++) {
        res += max(0,a[i-1]-a[i]);
        a[i] += max(0,a[i-1]-a[i]);
    }
    cout << res << '\n';
}