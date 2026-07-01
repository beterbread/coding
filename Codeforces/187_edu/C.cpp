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
	ll s,m; cin >> s>>m;

    if (m%2==0 && s%2==1) {
        cout << "-1\n";
        return;
    }
    vector<int> bits;
    while (m) {
        int bit = m & 1;
        bits.pb(bit);
        m >>= 1;
    }
    vector<ll> a;
    FOR(i,bits.size()) {
        if (bits[i]==0) continue;
        if ((1<<i) <= s) a.pb((1<<i));
    }

    vector<pair<ll,int>> res;
    FORD(i,a.size()) {
        if (a[i]<=s) {
            ll mod = s%a[i];
            ll div = (s-mod)/a[i];
            res.pb({a[i],div});
            s-=(s-mod);
        }
    }

    each(x,res) cout << x.ff << " " << x.ss << "\n";

    // cout << min(pos1,pos2) << "\n";
}

int main() 
{ 
	ios::sync_with_stdio(false); 
    cin.tie(nullptr);

	int t; cin >> t;
    while (t--) solve();
	
	return 0; 
} 
