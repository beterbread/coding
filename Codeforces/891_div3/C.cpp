#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> b(n*(n-1)/2);
        for (int& i : b) cin >> i;
        map<int,int> map;
        for (const int& i : b) map[i]++;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            if (map.empty()) {
                a[i] = 1e9;
                continue;
            }
            a[i] = map.begin()->first;
            map.begin()->second -= (n-i-1);
            if (map.begin()->second <= 0) map.erase(map.begin());
        }
        for (const int& i : a) cout << i << ' ';
        cout << '\n';
    }
}
