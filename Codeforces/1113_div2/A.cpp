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
    string a; cin >> a;
    int n = a.length();
    int alice = -1, bob = -1;
    FOR(i,n) {
        if (a[i] == '0') {
            alice = i;
            break;
        }
    }
    FOR(i,n) {
        if (a[i] == '1') {
            bob = i;
            break;
        }
    }
    FOR(i,n) {
        if (i == alice || i == bob) continue;
        cout << a[i];
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
