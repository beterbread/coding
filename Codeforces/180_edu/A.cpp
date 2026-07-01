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
	int a,x,y; cin >>a>>x>>y;

    for (int i = -200; i <= 200; i++) {
        if (i==a) continue;
        if (abs(i-x)<abs(a-x) && abs(i-y)<abs(a-y)) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}

int main() 
{ 
	ios::sync_with_stdio(false); 
    cin.tie(nullptr);

	int t; cin >> t;
    while (t--) solve();
	
	return 0; 
} 
