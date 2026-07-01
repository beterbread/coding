#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(),a.end());
    int res = 0;
    for (int i = 0; i < n; i++) {
        if (i==n-1) res++;
        else if (a[i] != a[i+1]) res++;
    }
    cout << res << '\n';
    return 0;
}