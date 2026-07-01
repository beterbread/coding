#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int& i : a) cin >> i;
        int mn = 1, mx = n;
        int l = 0, r = n-1;
        bool ok = false;
        while (r-l+1 > 3) {
            if (a[l]==mn) {
                l++;
                mn++;
            }
            else if (a[r]==mn) {
                r--;
                mn++;
            }
            else if (a[l]==mx) {
                l++;
                mx--;
            }
            else if (a[r]==mx) {
                r--;
                mx--;
            }
            else {
                cout << l+1 << ' ' << r+1 << '\n';
                ok = true;
                break;
            }
        }
        if (!ok) cout << "-1\n";
    }
}