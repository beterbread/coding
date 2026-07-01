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
    int n,m,l; cin >>n>>m>>l;
    vector<int> times(n);
    FOR(i,n) cin >>times[i];

    multiset<int> ms; 
    FOR(i,m) ms.insert(0); 

    int i = 0; // current time we are on
    for (int t = 1; t<=l; t++) {
        auto it = prev(ms.end());
        for (int k = 0; k < n-i && it!=ms.begin(); k++) it--;
        int tmp = *it;
        ms.erase(it);
        ms.insert(tmp+1);
        
        // cout << "current state at " << t << "\n";
        // for (auto it = ms.begin(); it!=ms.end(); it++) cout << *it << " ";
        // cout << "\n";

        if (i<n && times[i]==t) {
            auto it = prev(ms.end());
            ms.erase(it);
            ms.insert(0);
            i++;
        }
    }

    int res = 0;
    for (auto it = ms.begin(); it!=ms.end(); it++) res=max(res,*it);
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
