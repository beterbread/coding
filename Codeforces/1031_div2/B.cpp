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
	ll w,h,a,b; cin >>w>>h>>a>>b;
    ll x1,y1,x2,y2; cin >>x1>>y1>>x2>>y2;

    if (x1==x2) {
        if (abs(y1-y2)%b==0) cout << "Yes\n";
        else cout << "No\n";
        return;
    }
    if (y1==y2) {
        if (abs(x1-x2)%a==0) cout << "Yes\n";
        else cout << "No\n";
        return;
    }
    if ((x1-x2)%a==0 || (y1-y2)%b==0) cout << "Yes\n";
    else cout << "No\n";
}

int main() 
{ 
	ios::sync_with_stdio(false); 
    cin.tie(nullptr);

	int t; cin >> t;
    while (t--) solve();
	
	return 0; 
} 
