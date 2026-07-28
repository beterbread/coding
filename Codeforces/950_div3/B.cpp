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
    int n,f,k; cin >> n >> f >> k;
    vector<int> a(n);
    FOR(i,n) cin >> a[i];
    int og = a[f-1];
    sort(rall(a));
    bool joe = false, mama = false;
    FOR(i,k) {
        if (a[i] == og) {
            joe = true;
        }
    }
    for (int i = k; i < n; ++i) {
        if (a[i] == og) {
            mama = true;
        }
    }
    if (joe && mama) {
        cout << "MAYBE\n";
    }
    else if (joe) {
        cout << "YES\n";
    }
    else {
        cout << "NO\n";
    }
}

int main() 
{ 
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) solve();
    return 0; 
} 
