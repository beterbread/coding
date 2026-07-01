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

bool isRectangleOverlap(vector<int>& A, vector<int>& B) {
    return (A[0] < B[2] && A[2] > B[0] &&   // x overlap
            A[1] < B[3] && A[3] > B[1]);    // y overlap
}

int main() 
{ 
	fast_io

	int n;
    cin >> n;
    vector<vector<int>> recs;
	while (n--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        recs.pb({x1, y1, x2, y2});
    }
    n = recs.size();
    bool check = false;
    FOR(i, n) {
        rep(j, i + 1, n) {
            auto rec1 = recs[i];
            auto rec2 = recs[j];
            if (isRectangleOverlap(rec1, rec2)) {
                check = true;
                break;
            }
        }
        if (check) break;
    }
    if (check) cout << "Yes" << "\n";
    else cout << "No" << "\n";

	return 0; 
} 
