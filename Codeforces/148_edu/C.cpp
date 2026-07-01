#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int& i : a) cin >> i;

        vector<int> b; // remove consecutive equal elements
        for (int i = 0; i < n; ++i) {
            if (i < n-1 && a[i+1] == a[i]) continue;
            b.push_back(a[i]);
        }

        n = b.size();
        if (n <= 2) {
            cout << n << '\n';
            continue;
        }

        int res = 2;
        for (int i = 1; i < n-1; ++i) {
            if (b[i] < b[i-1] && b[i] < b[i+1]) res++;
            if (b[i] > b[i-1] && b[i] > b[i+1]) res++;
        }
        cout << res << '\n';
    }
}
