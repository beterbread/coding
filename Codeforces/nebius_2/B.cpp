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
    int x,y; cin >> x >> y;
    int n = x+y;
    vector<int> res(n);
    FOR(i,x) res[i]=1;
    for (int i = x; i<n; i++) res[i]=-1;

    ll cnt = 0;
    if (x==0 || y==0) {
        for (int i = 1; i<=n; i++) {
            if (n%i==0) cnt++; 
        }
    }
    else {
        cnt++;
        for (int i = 1; i<x; i++) {
            int joe = (y*-1)+i;
            if (joe>0 && (x-i)%joe==0) cnt++;
        }
        for (int i = 1; i<y; i++) {
            int joe = (x*-1)+i;
            if (joe>0 && (y-i)%joe==0) cnt++;
        }
    }
    cout << cnt%676767677 << '\n';
    each(i,res) cout << i << ' ';
    cout << '\n';
}

int main() 
{ 
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) solve();
    return 0; 
} 
