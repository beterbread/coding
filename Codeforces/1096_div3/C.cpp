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
    vector<int> fac_6;
    vector<int> fac_3;
    vector<int> fac_2;
    vector<int> joe;
    each(x,a) {
        if (x%6==0) fac_6.pb(x);
        else if (x%3==0) fac_3.pb(x);
        else if (x%2==0) fac_2.pb(x);
        else joe.pb(x);
    }
    each(x,fac_2) cout << x << ' ';
    each(x,joe) cout << x << ' ';
    each(x,fac_3) cout << x << ' ';
    each(x,fac_6) cout << x << ' ';
    cout << '\n';
}

int main() 
{ 
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) solve();
    return 0; 
} 
