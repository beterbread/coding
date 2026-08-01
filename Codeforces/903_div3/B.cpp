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
    int a,b,c; cin >> a >> b >> c;
    if (b == c) {
        if (a % 2 == 0 && a / 2 == b) {
            return void(cout << "YES\n");
        }
        if (a % 3 == 0 && a / 3 == b) {
            return void(cout << "YES\n");
        }
        if (a % 4 == 0 && a / 4 == b) {
            return void(cout << "YES\n");
        }
    }
    if (a == c) {
        if (b % 2 == 0 && b / 2 == a) {
            return void(cout << "YES\n");
        }
        if (b % 3 == 0 && b / 3 == a) {
            return void(cout << "YES\n");
        }
        if (b % 4 == 0 && b / 4 == a) {
            return void(cout << "YES\n");
        }
    }
    if (a == b) {
        if (c % 2 == 0 && c / 2 == a) {
            return void(cout << "YES\n");
        }
        if (c % 3 == 0 && c / 3 == a) {
            return void(cout << "YES\n");
        }
        if (c % 4 == 0 && c / 4 == a) {
            return void(cout << "YES\n");
        }
    }
    for (int i = 1; i <= 4; ++i) {
        for (int j = 1; j <= 4; ++j) {
            if ((i-1)+(j-1) > 3) continue;
            if (b % i == 0 && b / i == a && c % j == 0 && c / j == a) {
                return void(cout << "YES\n");
            }
            if (a % i == 0 && a / i == b && c % j == 0 && c / j == b) {
                return void(cout << "YES\n");
            }
            if (a % i == 0 && a / i == c && b % j == 0 && b / j == c) {
                return void(cout << "YES\n");
            }
        }
    }
    return void(cout << "NO\n");
}

int main() 
{ 
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) solve();
    return 0; 
} 
