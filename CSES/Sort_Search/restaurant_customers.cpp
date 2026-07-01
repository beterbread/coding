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

int main() 
{ 
	fast_io

    int n;
    cin >> n;

    vector<pair<int, int>> arr;
    FOR(i, n) {
        int a, b;
        cin >> a >> b;
        arr.pb({a, 1});
        arr.pb({b + 1, -1});
    }
    sort(all(arr));

    int res = 0;
    int curr = 0;
    each(x, arr) {
        curr += x.ss;
        res = max(res, curr);
    }
    cout << res << "\n";


    // Main takeaway: line sweep algorithm

	return 0; 
} 
