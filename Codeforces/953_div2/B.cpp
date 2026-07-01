#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long n,a,b; cin >>n>>a>>b;
    int l=0, r=min(n,b);
    while (l<r) {
        int mid = l+(r-l)/2;
        if (b-mid<a) r=mid;
        else l=mid+1;
    }
    cout << b*(b+1)/2 - (b-l)*(b-l+1)/2 + (n-l)*a << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}