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
    vector<int> l(n),r(n);
    FOR(i,n) {
        cin >> l[i];
        cin >> r[i];
    }
    vector<int> pre(2*n+2,0);
    vector<int> cnt(2*n+2,0);
    FOR(i,n) {
        if (l[i]==r[i]) {
            pre[l[i]]=1;
            cnt[l[i]]++;
        }
    }
    for (int i = 1; i <= 2*n; i++) {
        pre[i]+=pre[i-1];
    }
    FOR(i,n) {
        if (l[i]==r[i]) {
            cout << (cnt[l[i]]<=1 ? '1' : '0');
        }
        else if (pre[r[i]]-pre[l[i]-1] < (r[i]-l[i]+1)) {
            cout << '1';
        }   
        else {
            cout << '0';
        }
    }
    cout << '\n';
}

int main() 
{ 
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) solve();
    return 0; 
} 
