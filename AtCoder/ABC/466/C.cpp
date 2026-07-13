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
    int res = 0;
    for (int i = 1; i <= n-2; i+=2) {
        cout << "? " << i << ' ' << i+2 << endl;
        string response; cin >> response;
        if (response == "Yes") res+=2;
    }
    for (int i = 2; i <= n-2; i+=2) {
        cout << "? " << i << ' ' << i+2 << endl;
        string response; cin >> response;
        if (response == "Yes") res+=2;
    }
    cout << "! " << res << endl;
}

int main() 
{ 
    cin.tie(0)->sync_with_stdio(0);
    solve();
    return 0; 
} 
