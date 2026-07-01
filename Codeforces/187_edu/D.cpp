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
    int n,m; cin >>n>>m;
    vector<int> a(n), b(m);
    FOR(i,n) cin >>a[i];
    FOR(i,m) cin >>b[i];
    
    vector<int> freq(n+m+1,0);
    each(x,a) freq[x]++;
    
    vector<int> joe(n+m+1,0);
    for (int i = 1; i<=n+m; i++) {
        for (int j = i; j<=n+m; j+=i) {
            joe[j] += freq[i];
        }
    }
    
    int alice=0, bob=0, both=0;
    each(x,b) {
        if (joe[x]==n) alice++;
        else if (joe[x]==0) bob++;
        else both++;
    }
    
    if (alice+ceil((double)both/2) > bob+floor((double)both/2)) {
        cout << "Alice\n";
    }
    else {
        cout << "Bob\n";
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