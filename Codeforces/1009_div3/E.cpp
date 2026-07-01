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
    vector<int> a {3};
    int x=1,y=2,z=3;
    FOR(q,75) {
        if (a.size()==3) {
            x=a[0];
            y=a[1];
            z=a[2];
            a = {z};
        }
        cout << "? " << x << ' ' << y << ' ' << z << endl;
        int p; cin >> p;
        if (p==0) {
            cout << "! " << x << ' ' << y << ' ' << z << endl;
            return;
        }
        else {
            z = p;
            a.pb(z);
        }
    }
    cout << "-1" << endl;
}

int main() 
{ 
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) solve();
    return 0; 
} 
