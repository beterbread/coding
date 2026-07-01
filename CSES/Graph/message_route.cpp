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

void bfs(int start, vector<vector<int>>& adj) {
    int n = adj.size() - 1;
    unordered_map<int, int> visited;
    queue<int> q;
    q.push(start);
    visited[start] = start;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : adj[u]) {
            if (visited.find(v) != visited.end()) continue;
            q.push(v);
            visited[v] = u;

            
            if (v == n) {
                vector<int> res;
                int steps = 2;
                int step = visited[v];
                while (step != start) {
                    steps++;
                    res.pb(step);
                    step = visited[step];
                }
                reverse(all(res));
                string fin = "";
                for (int i : res) {
                    fin += (to_string(i) + " ");
                }
                cout << steps << "\n";
                cout << start << " " << fin << n << "\n";
                return;
            }
        }
    }
    cout << "IMPOSSIBLE" << "\n";
}

int main() 
{ 
	fast_io

    int n, m;
    cin >> n;
    cin >> m;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a;
        cin >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    bfs(1, adj);

	return 0; 
} 
