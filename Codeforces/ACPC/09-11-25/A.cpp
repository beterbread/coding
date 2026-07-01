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
    vector<vector<int>> scores = {{1,1,1,1,1,1,1,1,1,1},
                                 {1,2,2,2,2,2,2,2,2,1},
                                 {1,2,3,3,3,3,3,3,2,1},
                                 {1,2,3,4,4,4,4,3,2,1},
                                 {1,2,3,4,5,5,4,3,2,1},
                                 {1,2,3,4,5,5,4,3,2,1},
                                 {1,2,3,4,4,4,4,3,2,1},
                                 {1,2,3,3,3,3,3,3,2,1},
                                 {1,2,2,2,2,2,2,2,2,1},
                                 {1,1,1,1,1,1,1,1,1,1}};
	fast_io
	int t;
	cin >> t;
    while (t > 0) {
        int score = 0;
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                char c;
                cin >> c;
                if (c == 'X') score += scores[i][j];
            }
        }
        cout << score << endl;
        t--;
    }
	return 0; 
} 
