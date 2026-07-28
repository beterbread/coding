#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        string s; cin >> s;
        int res = 0;
        int l = 0, r = 0;
        while (r < n) {
            if (s[l] == '*') {
                l++;
                r++;
                continue;
            }
            int cur = 1;
            while (r+1 < n && s[r+1] == '#') {
                r++;
                cur++;
            }
            if (cur&1) res = max(res,(cur/2)+1);
            else res = max(res,cur/2);
            l = r+1;
            r = l;
        }
        cout << res << '\n';
    }
}