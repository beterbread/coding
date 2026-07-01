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

void dfs(int start, vector<vector<int>>& adj, vector<bool>& visited) {
    stack<int> st;
    st.push(start);
    visited[start] = true;

    while (!st.empty()) {
        int u = st.top();
        st.pop();

        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                st.push(v);
            }
        }
    }
}

int main() 
{ 
	fast_io

    int n, m;
    cin >> n;
    cin >> m;
    vector<vector<int>> adj(n + 1);
    int a, b;
    for (int i = 0; i < m; i++) {
        cin >> a;
        cin >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    int count = 0; // Number of connected components
    vector<int> roads; 
    vector<bool> visited(n + 1);
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(i, adj, visited);
            count++;
            roads.pb(i);
        }
    }
    cout << count - 1 << "\n";
    if (count >= 2) {
        for (size_t i = 0; i < roads.size() - 1; i++) {
            cout << roads[i] << " " << roads[i + 1] << "\n";
        }
    }

	return 0; 
} 