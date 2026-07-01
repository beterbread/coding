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
	int n; cin >>n;
    vector<ll> a(n);
    FOR(i,n) cin >>a[i];

    vector<int> ones(30,0);
    FOR(i,n) {
        int x = a[i];
        int place = 0;
        while (x) {
            int bit = x&1;
            ones[place]+=bit;
            x >>= 1;
            place++;
        }
    }

    ll joe = -1, mama = LLONG_MIN;
    FOR(i,n) {
        int x = a[i];
        ll good = 0;
        FOR(j,30) {
            int bit = x&(1LL<<j);
            if (bit) {
                good += (1LL<<j) * (n-ones[j]);
                good -= (1LL<<j) * ones[j];
            }
            else {
                good += (1LL<<j) * ones[j];
                good -= (1LL<<j) * (n-ones[j]);
            }
        }   
        if (good > mama) {
            joe = a[i];
            mama = good;
        }
    }

    ll res = 0;
    FOR(i,n) res += (a[i]^joe);
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
