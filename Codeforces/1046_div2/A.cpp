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
	int a,b,c,d; cin >>a>>b>>c>>d;

    c-=a;
    d-=b;
    // cout << abs(a-b) - min(a,b) << " " << abs(c-d) - min(c,d) << "\n";
    if (abs(a-b)-min(a,b) >= 3) {
        cout << "NO\n";
        return;
    }
    if (abs(c-d)-min(c,d) >= 3) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
}

int main() 
{ 
	ios::sync_with_stdio(false); 
    cin.tie(nullptr);

	int t; cin >> t;
    while (t--) solve();
	
	return 0; 
} 
