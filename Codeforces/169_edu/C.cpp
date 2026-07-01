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
    int n,k; cin >>n>>k;
    vector<int> a(n);
    FOR(i,n) cin >>a[i];

    sort(all(a));
    
    ll res = 0;
    bool alice = true;
    FORD(i,n) {
        if (alice) {
            res+=a[i];
            alice = false;
        }
        else {
            res-=min(a[i+1],a[i]+k);
            alice = true;
            k-=min(k,a[i+1]-a[i]);
        }
    }
    cout << res << "\n";
}

int main() 
{ 
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) solve();
	
    return 0; 
} 
