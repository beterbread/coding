#include <bits/stdc++.h> 
using namespace std; 

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
#define ff first
#define ss second
#define each(x, a) for (auto &x : a)                    
#define FOR(i, n) for (int i = 0; i < (n); ++i)           
#define FORD(i, n) for (int i = (n) - 1; i >= 0; --i)   

void solve() {
    int n; cin >> n;
    vector<ll> a(n-1);
    FOR(i,n-1) cin >> a[i];
    vector<int> perm(n+1,false);
    if (a[0] >= 1 && a[0] <= n) perm[a[0]]++;
    FOR(i,n-2) {
        ll diff = a[i+1] - a[i];
        if (diff <= n) perm[diff]++;
    }
    int cnt = 0;
    ll sum = 0;
    for (int i = 1; i <= n; ++i) {
        if (!perm[i]) {
            cnt++;
            sum += i;
        }
    }
    if (cnt == 1) {
        cout << "YES\n";
        return;
    }
    if (cnt > 2) {
        cout << "NO\n";
        return;
    }
    if (a[0] == sum && (sum > n || perm[sum] > 1)) {
        cout << "YES\n";
        return;
    }
    FOR(i,n-2) {
        ll diff = a[i+1] - a[i];
        if (diff == sum && (sum > n || perm[sum] > 1)) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}

int main() 
{ 
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) solve();
    return 0; 
} 
