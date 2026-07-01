#include <bits/stdc++.h>
using namespace std;
 
void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (int& x : a) cin >> x;
    for (int i = 0; i < n-1; i++) {
        int x=a[i], y=a[i+1];
        int z1=x, z2=y;
        if (x+y>z1 && x+z1>y && y+z1>x && x+y>z2 && x+z2>y && y+z2>x) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}
 
int main() {
    int t; cin >> t;
    while (t--) solve();
    return 0;
}