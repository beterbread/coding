#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n,m; cin >> n >> m;
    vector<vector<int>> adj(n+1);
    while (m--) {
        int a,b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<bool> visited(n+1,false);
    priority_queue<int,vector<int>,greater<int>> pq;
    pq.push(1);
    while (!pq.empty()) {
        int a = pq.top(); pq.pop();
        if (visited[a]) continue;
        cout << a << ' ';
        visited[a] = true;
        for (const int& b : adj[a]) {
            pq.push(b);
        }
    }
    cout << '\n';
}