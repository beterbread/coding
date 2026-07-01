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

void dfs(int x, int y, vector<vector<bool>>& visited, vector<vector<char>>& grid) {
    if (x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size()) {
        return;
    }
    if (visited[x][y] || grid[x][y] == '#') {
        return;
    }
    visited[x][y] = true;
    dfs(x + 1, y, visited, grid);
    dfs(x - 1, y, visited, grid);
    dfs(x, y + 1, visited, grid);
    dfs(x, y - 1, visited, grid);
}

int main() 
{ 
	fast_io

    int n, m;
    cin >> n;
    cin >> m;
    vector<vector<char>> grid(n, vector<char>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    int res = 0;
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visited[i][j] && grid[i][j] == '.') {
                res++;
                dfs(i, j, visited, grid);
            }
        }
    }
    cout << res << "\n";

	return 0; 
} 
