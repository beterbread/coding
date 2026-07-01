#include <bits/stdc++.h> 
using namespace std; 

using ll = long long;
using ull = unsigned long long;
using ld = long double;
const ll MOD = 1e9 + 7;
const ll INF = 1e18;
const int INF_INT = 1e9;
const ld EPS = 1e-9;
#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
#define ff first
#define ss second

int main() 
{ 
	fast_io
	int t;
	cin >> t;
	while (t > 0) {
        int a, b, c;
        cin >> a;
        cin >> b; 
        cin >> c;
        int mx = max(a,max(b,c));
        int mn = min(a,min(b,c));
        if (a != mx && a != mn) cout << a << endl;
        if (b != mx && b != mn) cout << b << endl;
        if (c != mx && c != mn) cout << c << endl;
        t--;
	}
	return 0; 
} 
