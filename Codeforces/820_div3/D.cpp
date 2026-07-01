#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> x(n),y(n);
        for (int& i : x) cin >> i;
        for (int& i : y) cin >> i;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) a[i] = y[i] - x[i];
        sort(a.begin(),a.end());
        int res = 0;
        int l = 0, r = n-1;
        while (l < r) {
            if (a[l] + a[r] >= 0) {
                res++;
                l++;
                r--;
            }
            else {
                l++;
            }
        }
        cout << res << '\n';
    }
}
