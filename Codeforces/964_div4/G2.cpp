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
    int l=2,r=999;
    while (l < r) {
        int m1 = l+(r-l)/3;
        int m2 = r-(r-l)/3;
        cout << "? " << m1 << ' ' << m2 << endl;
        int q; cin >> q;  
        if (q == (m1+1)*(m2+1)) {
            r = m1;
        }  
        else if (q == m1*(m2+1)) {
            r = m2;
            l = m1+1;
        }
        else {
            l = m2+1;
        }
    }
    cout << "! " << l << endl;
}

int main() 
{ 
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) solve();
    return 0; 
} 
