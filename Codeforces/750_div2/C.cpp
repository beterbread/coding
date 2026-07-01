#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        string s; cin >> s;
        int res = INT_MAX;
        for (char c = 'a'; c <= 'z'; c++) {
            int l = 0, r = n-1;
            int ops = 0;
            while (l < r) {
                if (s[l] == s[r]) {
                    l++;
                    r--;
                }
                else if (s[l] == c) {
                    l++;
                    ops++;
                }
                else if (s[r] == c) {
                    r--;
                    ops++;
                }
                else {
                    ops = INT_MAX;
                    break;
                }
            }
            res = min(res,ops);
        }
        cout << (res == INT_MAX ? -1 : res) << '\n';
    }
}
