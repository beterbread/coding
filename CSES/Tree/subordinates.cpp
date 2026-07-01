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
#define rep(i, a, b) for (int i = (a); i < (b); ++i)       
#define repd(i, a, b) for (int i = (a); i >= (b); --i)    
#define each(x, a) for (auto &x : a)                    
#define FOR(i, n) for (int i = 0; i < (n); ++i)           
#define FORD(i, n) for (int i = (n) - 1; i >= 0; --i)   

int recurse(int curr, vector<vector<int>>& children, vector<int>& sub) {
    if (children[curr].size() == 0) {
        return 1;
    }
    int sum = 0;
    each(i, children[curr]) sum += recurse(i, children, sub);
    sub[curr] = sum; // This node's # of children
    return 1 + sum; // Include this node + its # of children for the parent of this node
}

int main() 
{ 
	fast_io
	
    int n;
    cin >> n;
    vector<vector<int>> children(n + 1);
    int num;
    rep(i, 2, n + 1) {
        cin >> num;
        children[num].pb(i);
    }

    vector<int> sub(n + 1);
    recurse(1, children, sub);
    rep(i, 1, n + 1) cout << sub[i] << " ";
    cout << "\n";

    // Key takeaway: Basic tree recursion, # of children for each node

	return 0; 
} 
