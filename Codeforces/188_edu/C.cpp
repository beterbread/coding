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
    ll a,b,c,m; cin >>a>>b>>c>>m;

    ll a_res = 0;
    ll x = floor(ld(m)/a); 
    ll y = floor(ld(m)/lcm(a,b));
    ll z = floor(ld(m)/lcm(a,c));
    ll zz = floor(ld(m)/lcm(lcm(a,b),lcm(a,c)));
    a_res += (x-(y+z-zz))*6LL;
    a_res += ((y-zz)+(z-zz))*3LL;
    a_res += zz*2LL;

    ll b_res = 0;
    x = floor(ld(m)/b); 
    y = floor(ld(m)/lcm(b,a));
    z = floor(ld(m)/lcm(b,c));
    zz = floor(ld(m)/lcm(lcm(b,a),lcm(b,c)));
    b_res += (x-(y+z-zz))*6LL;
    b_res += ((y-zz)+(z-zz))*3LL;
    b_res += zz*2LL;

    ll c_res = 0;
    x = floor(ld(m)/c); 
    y = floor(ld(m)/lcm(c,a));
    z = floor(ld(m)/lcm(c,b));
    zz = floor(ld(m)/lcm(lcm(c,a),lcm(c,b)));
    c_res += (x-(y+z-zz))*6LL;
    c_res += ((y-zz)+(z-zz))*3LL;
    c_res += zz*2LL;

    cout << a_res << " " << b_res << " " << c_res << "\n";
}

int main() 
{ 
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) solve();
	
    return 0; 
} 
