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
    string x; cin >>x;

    if(n%2==1 && x[0]=='b') {
        cout << "NO\n";
        return;
    }
    if(n%2==1) {
        for (int i = 1; i < n-1; i+=2) {
            if (x[i]!='?' && x[i]==x[i+1]) {
                cout << "NO\n";
                return;
            }
        }
    }
    else {
        for (int i = 1; i < n; i+=2) {
            if (x[i]!='?' && x[i]==x[i-1]) {
                cout << "NO\n";
                return;
            }
        }
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
