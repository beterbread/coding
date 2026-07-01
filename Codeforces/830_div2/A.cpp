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

int gcdall(vector<int>& a) {
    int res = a[1];
    for (int i = 2; i < a.size(); i++) res = gcd(res,a[i]);
    return res;
}

void solve() {
    int n; cin >> n;
    vector<int> a(n+1);
    for (int i = 1; i < n+1; i++) cin >> a[i];
    if (gcdall(a)==1) {
        cout << "0\n";
        return;
    }
    int og = a[n];
    a[n] = gcd(a[n],n);
    if (gcdall(a)==1) {
        cout << "1\n";
        return;
    }
    a[n] = og;
    og = a[n-1];
    a[n-1] = gcd(a[n-1],n-1);
    if (gcdall(a)==1) {
        cout << "2\n";
        return;
    }
    cout << "3\n";
}

int main() 
{ 
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) solve();
    return 0; 
} 
