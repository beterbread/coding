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
    vector<int> a(m);
    FOR(i,m) cin >>a[i];

    set<int> set(all(a));
    for (int i = 0; i<n; i+=2) {
        if (set.size()==1) {
            FOR(j,6) {
                cout << *set.begin() << " ";
            }
            cout << "\n";
            break;
        }
        FOR(j,3) {
            cout << *set.begin() << " " << *prev(set.end()) << " ";
        }
        cout << "\n";
        if (i+1<n) {
            FOR(j,3) {
                cout << *prev(set.end()) << " " << *set.begin() << " ";
            }
            cout << "\n";
        }
        set.erase(set.begin());
        set.erase(prev(set.end()));
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
