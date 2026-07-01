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
	int n; cin >> n;
    string s; cin >> s;

    int x=0, y=0;
    FOR(i,n) {
        if (s[i]=='1') x++;
        else y++;
    }

    if (x==0) {
        cout << "0\n";
        return;
    }
    if(y%2==1) {
        cout << y << "\n";
        FOR(i,n) if(s[i]=='0') cout << i+1 << " ";
        cout << "\n";
    }
    else if (x%2==0) {
        cout << x << "\n";
        FOR(i,n) if(s[i]=='1') cout << i+1 << " ";
        cout << "\n";
    }
    else {
        cout << "-1\n";
    }
}

int main() 
{ 
	ios::sync_with_stdio(false); 
    cin.tie(nullptr);

	int t; cin >> t;
    while (t--) solve();
	
	return 0; 
} 
