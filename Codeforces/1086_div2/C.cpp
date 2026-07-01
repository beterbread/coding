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
    vector<ld> c(n),p(n);
    FOR(i,n) {
        cin >>c[i];
        cin >>p[i];
    }

    ld res = 0;
    for (int i = n-1; i>=0; i--) {
        res = max(res,res*(1.0L-(p[i]/100.0L))+c[i]);
    }
    cout << setprecision(10) << res << "\n";
}

int main() 
{ 
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) solve();
	
    return 0; 
} 
