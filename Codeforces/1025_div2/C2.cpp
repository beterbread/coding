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

    // A number is divisible by 9 if the sum of its digits is a multiple of 9
    // first multiply x by 9
    // mult 9
    // now S(x) should be divisible by 9
    // digit
    // digit
    // now x = 9?
    // add n-9

    int trash;
    cout << "mul 9" << endl; cin >> trash;
    cout << "digit" << endl; cin >> trash;
    cout << "digit" << endl; cin >> trash;
    cout << "add " << n-9 << endl; cin >> trash;
    cout << "!" << endl; cin >> trash;
}

int main() 
{ 
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) solve();
    
    return 0; 
} 