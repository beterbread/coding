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

    int n, m, k;
    cin >> n;
    cin >> m;
    cin >> k;
    vector<int> desired(n);
    vector<int> size(m);
    for (int i = 0; i < n; i++) cin >> desired[i];
    for (int i = 0; i < m; i++) cin >> size[i];

    sort(all(desired));
    sort(all(size));
    int res = 0;
    int j = 0;
    for (int i = 0; i < n; i++) {
        while (j < m && desired[i] - k > size[j]) {
            j++;
        }   
        if (j == m) break;
        if (abs(desired[i] - size[j]) <= k) {
            res++;
            j++;
        }
    }
    cout << res << "\n";

	return 0; 
} 
