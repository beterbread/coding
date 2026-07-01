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
    int m,a,b,c; cin >> m >> a >> b >> c;
    int row1=m,row2=m;
    int res=0;
    int joe=min(row1,a);
    row1-=joe;
    res+=joe;
    joe=min(row2,b);
    row2-=joe;
    res+=joe;
    joe=min(row1,c);
    c-=joe;
    res+=joe;
    joe=min(row2,c);
    res+=joe;
    cout << res << '\n';
}

int main() 
{ 
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) solve();
    return 0; 
} 
