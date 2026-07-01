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

unordered_set<int> factors(int n) {
    unordered_set<int> f;
    for (int x = 2; x * x <= n; x++) {
        while (n % x == 0) {
            f.insert(x);
            n /= x;
        }
    }
    if (n > 1) f.insert(n);
    return f;
}

void solve() {
	int n; cin >>n;

    unordered_set<int> a = factors(n);
    int res = 1;
    each(x,a) res*=x;
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
