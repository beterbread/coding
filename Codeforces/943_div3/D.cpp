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
    ll n,k,Pb,Ps; cin >> n >> k >> Pb >> Ps;
    Pb--; Ps--; // zero indexing
    vector<ll> p(n),a(n);
    FOR(i,n) cin >> p[i];
    FOR(i,n) cin >> a[i];
    ll b_score = 0, s_score = 0;
    ll so_far = 0;
    FOR(i,min(n,k)) {
        so_far += a[Pb];
        b_score = max(b_score,so_far + a[Pb]*max(0LL,k-(i+1)));
        Pb = p[Pb]-1;
    }
    so_far = 0;
    FOR(i,min(n,k)) {
        so_far += a[Ps];
        s_score = max(s_score,so_far + a[Ps]*max(0LL,k-(i+1)));
        Ps = p[Ps]-1;
    }
    if (b_score > s_score) {
        cout << "Bodya\n";
    }
    else if (s_score > b_score) {
        cout << "Sasha\n";
    }
    else {
        cout << "Draw\n";
    }
}

int main() 
{ 
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) solve();
    return 0; 
} 
