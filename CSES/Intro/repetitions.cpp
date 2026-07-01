#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    string s; cin >> s;
    int n = s.length();
    int l=0, r=0;
    int res = 1;
    while (r<n) {
        while (r+1<n && s[l]==s[r+1]) r++;
        res = max(res,r-l+1);
        l=r+1;
        r=l;
    }
    cout << res << '\n';
}