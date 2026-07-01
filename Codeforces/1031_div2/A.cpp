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
    ll k,a,b,x,y; cin >> k>>a>>b>>x>>y;

    if (x>y) {
        swap(x,y);
        swap(a,b);
    }

    ll res = 0;
    if (k >= a) {
        ll cook = k==a ? 1 : ceil(ld(k-a)/x);
        res+=cook;
        k-=(cook*x);
        if (k >= a) {
            k-=x;
            res++;
        }
    }
    if (k >= b) {
        ll cook = k==b ? 1 : ceil(ld(k-b)/y);
        res+=cook;
        k-=(cook*y);
        if (k >= b) res++;
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
