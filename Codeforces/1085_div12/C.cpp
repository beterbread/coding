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
    ll n,h; cin >>n>>h;
    vector<ll> a(n);
    FOR(i,n) cin >>a[i];

    // first drain
    ll idx = -1, mama = 0;
    FOR(i,n) {
        ll joe = h-a[i];
        ll mx = a[i];
        for (int l=i-1; l>=0; l--) {
            joe += h-max(mx,a[l]);
            mx = max(mx,a[l]);
        }
        mx = a[i];
        for (int r=i+1; r<n; r++) {
            joe += h-max(mx,a[r]);
            mx = max(mx,a[r]);
        }
        if (joe>mama) {
            mama=joe;
            idx=i;
        }
    }   

    if (idx==-1) {
        cout << 0 << "\n";
        return;
    }

    // decrement water
    vector<int> buhao(n,0); 
    ll joe = h-a[idx];
    ll mx = a[idx];
    buhao[idx]+=h-a[idx];
    for (int l=idx-1; l>=0; l--) {
        buhao[l] += h-max(mx,a[l]);
        joe += h-max(mx,a[l]);
        mx = max(mx,a[l]);
    }
    mx = a[idx];
    for (int r=idx+1; r<n; r++) {
        buhao[r] += h-max(mx,a[r]);
        joe += h-max(mx,a[r]);
        mx = max(mx,a[r]);
    }

    // each(x,buhao) cout << x << " ";
    // cout << "\n";

    ll mama2 = 0;
    FOR(i,n) {
        ll joe = h-a[i]-buhao[i];
        ll mx = a[i];
        for (int l=i-1; l>=0; l--) {
            joe += max(0LL,h-max(mx,a[l])-buhao[l]);
            mx = max(mx,a[l]);
        }
        mx = a[i];
        for (int r=i+1; r<n; r++) {
            joe += max(0LL,h-max(mx,a[r])-buhao[r]);
            mx = max(mx,a[r]);
        }
        mama2 = max(joe,mama2);
    }
      
    cout << mama+mama2 << "\n";
}

int main() 
{ 
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) solve();
	
    return 0; 
} 
