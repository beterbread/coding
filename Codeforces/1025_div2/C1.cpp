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
    int n; cin >>n;

    // 999,999,999
    // sum 1 to 81 (highest S(x) from this range is x=79)
    // sum 1 to 16
    // with two ops, we ensure our x is in the range 1 to 16 
    // add -8
    // add -4
    // add -2
    // add -1
    // with four ops, x=1
    // add n-1

    int trash;
    cout << "digit" << endl;
    cin >> trash;
    cout << "digit" << endl;
    cin >> trash;
    cout << "add -8" << endl;
    cin >> trash;
    cout << "add -4" << endl;
    cin >> trash;
    cout << "add -2" << endl;
    cin >> trash;
    cout << "add -1" << endl;
    cin >> trash;
    cout << "add " << n-1 << endl;
    cin >> trash;
    cout << "!" << endl;
    cin >> trash;
}

int main() 
{ 
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) solve();
    
    return 0; 
} 