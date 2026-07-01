#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >>n;
    vector<long long> a(n);
    for (auto& i : a) cin >>i;
    cout << (a[n-1]+*max_element(a.begin(),a.end()-1)) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}