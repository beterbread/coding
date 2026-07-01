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

    int t;
    cin >> t;
    while (t > 0) {
        int n;
        cin >> n;
        vector<int> arr(n);
        FOR(i, n) cin >> arr[i];

        unordered_map<int, int> m;
        int l = 0;
        int r = 0;
        int count = 0;
        m[arr[l]]++;
        while (r < n) {
            if ((l == 0 || arr[l - 1] > arr[l]) &&
                (r == n - 1 || arr[r] < arr[r + 1]) &&
                m.size() == 1) {
                count++;
                r++;
                m[arr[r]]++;
                continue;
            }
            if (!(l == 0 || arr[l - 1] > arr[l]) || m.size() > 1) {
                if (l < r) {
                    l++;
                    m[arr[l]]--;
                    if (m[arr[l]] == 0) m.erase(arr[l]);
                    continue;
                }
            }
            if (r < n && !(r == n - 1 || arr[r] < arr[r + 1])) {
                r++;
                m[arr[r]]++;
                continue;
            }
        }
        if (count == 1) {
            cout << "YES" << "\n";
        }
        else {
            cout << "NO" << "\n";
        }
        t--;
    }
	return 0; 
} 
