#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n,k; cin >> n >> k;
        vector<int> a(n);
        for (int& i : a) cin >> i;
        int mx = *max_element(a.begin(),a.end());
        int mx2 = -1;
        for (auto& x : a) {
            if (x < mx) mx2 = max(mx2,x);
        }
        bool res = false;
        if (!(mx&1)) res = true;
        if (mx2 != -1) {
            if (mx-mx2 <= k) {
                
            }
        }
    }
}
