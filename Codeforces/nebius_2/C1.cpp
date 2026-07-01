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
    int n,k; cin >> n >> k;
    vector<int> a(n),b(n);
    FOR(i,n) cin >> a[i];
    FOR(i,n) cin >> b[i];
    unordered_map<int,int> joe;
    each(x,b) {
        if (x!=-1) joe[x]++;
        if (joe[x]>1) {
            cout << "NO\n";
            return;
        }
    }
    vector<int> mama(n);
    FOR(i,n) mama[a[i]]=i;
    FOR(i,n) {
        if (b[i]!=-1) {
            int l = max(0,mama[b[i]]-k+1), r = min(n,mama[b[i]]+k-1);
            if (i+k-1<r || i-k+1<l) {
                cout << "NO\n";
                return;
            }
        }
    }
    cout << "YES\n";
}

int main() 
{ 
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) solve();
    return 0; 
} 
