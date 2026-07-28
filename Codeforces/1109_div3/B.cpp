#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<long long> a(n);
        for (long long& i : a) cin >> i;
        bool res = true;
        for (int i = 0; i < n-1; ++i) {
            long long take = i > 0 ? a[i] - a[i-1] - 1 : a[i] - 1;
            take = max(0LL,take);
            a[i] -= take;
            a[i+1] += take;
            if (a[i] >= a[i+1]) {
                res = false;
                break;
            }
        }
        cout << (res ? "YES" : "NO") << '\n';
    }
}