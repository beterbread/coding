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

string solution(pair<int, int> a, pair<int, int> b, vector<vector<char>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<char>> visited(n, vector<char>(m, '0')); // '0' for not visited
    queue<pair<int, int>> q;
    q.push(a);
    visited[a.ff][a.ss] = 's'; // 's' for starting node

    vector<vector<int>> dir = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        for (const auto& d : dir) {
            char path = d[1] == 0 ? (d[0] == 1 ? 'D' : 'U') : (d[1] == 1 ? 'R' : 'L');
            int nx = x + d[0];
            int ny = y + d[1];
            if (nx >= 0 && ny >= 0 && nx < n && ny < m) {
                if (grid[nx][ny] == 'B') { // Found result
                    visited[nx][ny] = path;
                    int steps = 0;
                    string res = "";
                    while (visited[nx][ny] != 's') { // Backtrack + construct steps
                        char step = visited[nx][ny];
                        res.pb(step);
                        if (step == 'D') nx -= 1;
                        else if (step == 'U') nx += 1;
                        else if (step == 'R') ny -= 1;
                        else if (step == 'L') ny += 1;
                        steps++;
                    }
                    reverse(all(res));
                    return "YES\n" + to_string(steps) + "\n" + res + "\n";
                }
                if (grid[nx][ny] == '.' && visited[nx][ny] == '0') {
                    q.push({nx, ny});
                    visited[nx][ny] = path;
                }
            }
        }        
    }
    return "NO\n";
}

int main() 
{ 
	fast_io

    int n, m;
    cin >> n;
    cin >> m;   
    pair<int, int> a, b;
    vector<vector<char>> grid(n, vector<char>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 'A') {
                a = {i, j};
            }
            else if (grid[i][j] == 'B') {
                b = {i, j};
            }
        }
    }
    cout << solution(a, b, grid);
    
	return 0; 
} 
