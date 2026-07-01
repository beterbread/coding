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
	string p,s; cin >>p>>s;

    vector<pair<char,int>> p_b, s_b;
    int cur = 1;
    FOR(i,p.length()) {
        if (i==p.length()-1 || p[i] != p[i+1]) {
            p_b.pb({p[i],cur});
            cur = 1;
        }
        else {
            cur++;
        }
    }
    cur = 1;
    FOR(i,s.length()) {
        if (i==s.length()-1 || s[i] != s[i+1]) {
            s_b.pb({s[i],cur});
            cur = 1;
        }
        else {
            cur++;
        }
    }
    
    // each(x,p_b) {
    //     cout << x.ff << " " << x.ss << " ";
    // }
    // cout << "\n";
    // each(x,s_b) {
    //     cout << x.ff << " " << x.ss << " ";
    // }

    if (p_b.size()!=s_b.size()) {
        cout << "NO\n";
        return;
    }
    FOR(i,p_b.size()) {
        if (p_b[i].ff!=s_b[i].ff) {
            cout << "NO\n";
            return;
        }
        int x = p_b[i].ss, y = s_b[i].ss;
        if (!(y>=x && y<=x*2)) {
            cout << "NO\n";
            return;
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
