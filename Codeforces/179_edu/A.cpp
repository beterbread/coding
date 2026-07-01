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
    int x; cin >>x;
    
    int res = 0;
    int a=0,b=0,c=0;
    while (a!=x || b!=x || c!=x) {
        int mn = min(a,min(b,c));
        if (a==mn) {
            a = min(2*min(b,c)+1,x);
        }
        else if (b==mn) {
            b = min(2*min(a,c)+1,x);
        }
        else {
            c = min(2*min(a,b)+1,x);
        }
        res++;
        // cout << a << " " << b << " " << c << "\n";
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
