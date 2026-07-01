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

bool palindrome(ll x) {
    string s = to_string(x);
    int l = 0, r = s.length()-1;
    while (l < r)  {
        if (s[l] != s[r]) return false;
        l++;
        r--;
    }
    return true;
}

void solve() {
    ll n; cin >> n;
    for (ll a = 0; a <= 99; a++) {
        if (palindrome(a)) {
            ll b = n-a;
            if (b>=0 && b%12==0) {
                cout << a << ' ' << b << '\n';
                return;
            }
        }
    }
    cout << "-1\n";
}

int main() 
{ 
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) solve();
    return 0; 
} 
