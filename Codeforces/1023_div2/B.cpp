#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n,k; cin >> n >> k;
    vector<int> a(n);
    for (int& i : a) cin >> i;

    int mn = *min_element(a.begin(),a.end());
    int mx = *max_element(a.begin(),a.end());
    if (mx-mn > k) {
        int cnt = count(a.begin(),a.end(),mx);
        if (mx-mn-1 > k) {
            cout << "Jerry\n";
            return;
        }
        else if (cnt > 1) {
            cout << "Jerry\n";
            return;
        }
    }
    long long sum = accumulate(a.begin(),a.end(),0LL);
    cout << (sum&1 ? "Tom" : "Jerry") << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}