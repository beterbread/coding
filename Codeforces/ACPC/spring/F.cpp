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
    int A; cin >> A;
    if (A==1) {
        cout << ".O." << endl;
        cout << "OPO" << endl;
        cout << ".O." << endl;
    }
    else if (A==2) {
        cout << ".O." << endl;
        cout << "OPO" << endl;
        cout << "OPO" << endl;
        cout << ".O." << endl;
    }
    else if (A==3) {
        cout << ".O.." << endl;
        cout << "OPO." << endl;
        cout << "OPPO" << endl;
        cout << ".OO." << endl;
    }
    else if (A==4) {
        cout << "..O.." << endl;
        cout << ".OPO." << endl;
        cout << "OPPPO" << endl;
        cout << ".OOO." << endl;
        cout << "....." << endl;
    }
    else if (A==5) {
        cout << "..O.." << endl;
        cout << ".OPO." << endl;
        cout << "OPPPO" << endl;
        cout << ".OPO." << endl;
        cout << "..O.." << endl;
    }
    else if (A==67) {

    }
}

int main() 
{ 
    cin.tie(0)->sync_with_stdio(0);
    solve();
    return 0; 
} 
