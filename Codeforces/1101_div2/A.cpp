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
    vector<int> a(n);
    FOR(i,n) cin >> a[i];
    sort(all(a));
    int res = INT_MAX;
    FOR(i,n) {
        int pos1 = 0, pos2 = 0;
        for (int j = 0; j < i; j++) {
            if (a[i] != a[j]) pos1++;
        }
        for (int j = i+1; j < n; j++) {
            if (a[i] != a[j]) pos2++;
        }
        res = min(res,max(pos1,pos2));
    }
    cout << res << '\n';
}

int main() 
{ 
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) solve();
    return 0; 
} 
