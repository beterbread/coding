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

int blocks(string x) {
    int cnt = 0, cur = 0;
    FOR(i,x.length()) {
        if (i == x.length()-1 || x[i] != x[i+1]) {
            cnt++;
            cur=1;
        }
        else {
            cur++;
        }
    }
    return cnt;
}

void solve() {
	int n; cin >> n;
    string s; cin >> s;

    int res = 0;
    FOR(i,n) {
        string x = s;
        rotate(x.begin(),x.begin()+i,x.end());
        res = max(res,blocks(x));
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
