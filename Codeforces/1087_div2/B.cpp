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
    vector<ll> a(n);
    FOR(i,n) cin >> a[i];

    vector<int> res(n);
    FOR(i,n) {
        int cnt = 0, cnt2 = 0;
        for (int j = i+1; j < n; j++) {
            cnt += (a[i] > a[j]);
            cnt2 += (a[j] > a[i]);
        }
        res[i] = max(cnt,cnt2);
    }
    each(x,res) cout << x << " ";
    cout << "\n";
}

int main() 
{ 
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) solve();
	
    return 0; 
} 
