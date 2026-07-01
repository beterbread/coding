#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    vector<string> a(n);
    for (string& s : a) cin >> s;
    int res = 0;
    for (int i = 1; i < n-1; i++) {
        for (int j = 1; j < n-1; j++) {
            if (a[i][j]=='X' && a[i-1][j-1]=='X' && a[i+1][j+1]=='X' && a[i-1][j+1]=='X' && a[i+1][j-1]=='X') res++;
        }
    }
    cout << res << '\n';
}