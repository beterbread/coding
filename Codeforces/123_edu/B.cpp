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
    vector<int> joe(n);
    iota(all(joe),1);
    reverse(all(joe));
    each(x,joe) cout << x << ' ';
    cout << '\n';
    for (int i = 0; i < n-1; i++) {
        swap(joe[i],joe[i+1]);
        each(x,joe) cout << x << ' ';
        cout << '\n';
        swap(joe[i],joe[i+1]);
    }
}

int main() 
{ 
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) solve();
    return 0; 
} 
