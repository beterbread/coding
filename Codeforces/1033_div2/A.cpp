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
    int l1,b1,l2,b2,l3,b3; cin >>l1>>b1>>l2>>b2>>l3>>b3;

    if (l1==l2 && l2==l3 && b1+b2+b3==l1) {
        cout << "YES\n";
        return;
    }
    if (b1==b2 && b2==b3 && l1+l2+l3==b1) {
        cout << "YES\n";
        return;
    }
    if (l3==l2 && b3+b2==b1 && l3+l1==b1) {
        cout << "YES\n";
        return;
    }
    if (b3==b2 && l3+l2==l1 && b3+b1==l1) {
        cout << "YES\n";
        return;
    }
    cout << "NO\n";
}

int main() 
{ 
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) solve();
	
	return 0; 
} 
