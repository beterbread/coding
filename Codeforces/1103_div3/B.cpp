#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n,k; cin >> n >> k;
        string s; cin >> s;
        for (int i = 0; i < n-k; ++i) {
            if (s[i] == '1') {
                s[i] = '0';
                s[i+k] = s[i+k]=='1' ? '0' : '1';
            }
        }
        cout << (find(s.begin(),s.end(),'1')==s.end() ? "YES" : "NO") << '\n';
    }
}
