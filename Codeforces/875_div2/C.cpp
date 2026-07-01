#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<vector<pair<int,int>>> adj(n+1);
        for (int i = 0; i < n-1; ++i) {
            int x,y; cin >> x >> y;
            adj[x].push_back({y,i+1});
            adj[y].push_back({x,i+1});
        }
        vector<int> val(n+1,-1), a(n+1,-1);
        val[1] = 0;
        a[1] = 0;
        stack<int> st;
        vector<bool> visited(n+1,false);
        st.push(1);
        visited[1] = true;
        while (!st.empty()) {
            int x = st.top(); st.pop();
            for (auto& [y,idx] : adj[x]) {
                if (visited[y]) continue;
                visited[y] = true;
                val[y] = val[x] + (idx < a[x]);
                a[y] = idx;
                st.push(y);
            }
        }
        cout << *max_element(val.begin(),val.end()) + 1 << '\n';
    }
}