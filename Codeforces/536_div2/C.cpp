#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    vector<int> a(n);
    for (int& i : a) cin >> i;
    long long res = 0;
    sort(a.begin(),a.end());
    for (int i = 0; i < n/2; i++) {
        res += (a[i]+a[n-i-1])*(a[i]+a[n-i-1]);
    }
    cout << res << '\n';
}