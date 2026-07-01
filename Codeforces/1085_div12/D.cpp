#include <bits/stdc++.h> 
using namespace std; 

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
#define ff first
#define ss second
#define each(x, a) for (auto &x : a)                    
#define FOR(i, n) for (int i = 0; i < (n); ++i)           
#define FORD(i, n) for (int i = (n) - 1; i >= 0; --i)   

void dfs(int s, int dist, vector<vector<int>>& adj, vector<bool>& visited, vector<int>& joe, vector<int>& mama) {
    if (visited[s]) {
        return;
    }
    if (joe[s]>=2) {
        if (dist==0) {
            FOR(i,joe[s]) mama.pb(0);
        }
        else {
            mama.pb(dist);
        }
    }
    if (joe[s]==1) {
        mama.pb(dist+1);
    }   
    visited[s] = true;
    for (const int& u : adj[s]) {
        dfs(u,dist+1,adj,visited,joe,mama);
    }
}

void solve() {
    int n,k,v; cin >>n>>k>>v;
    vector<int> degree(n+1);
    vector<vector<int>> adj(n+1); 
    FOR(i,n-1) {
        int a,b; cin >>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
        degree[a]++;
        degree[b]++;
    }

    // for (int i = 1; i <= n; i++) cout << degree[i] << " ";

    vector<int> joe(n+1); 
    vector<bool> visited(n+1,false);
    stack<int> st;
    visited[v] = true;  
    st.push(v);
    while (!st.empty()) {
        int u = st.top(); 
        st.pop();
        for (int v : adj[u]) {
            if (!visited[v]) {
                if (degree[v]==1) joe[u]++;
                visited[v] = true;
                st.push(v);
            }
        }
    }

    // each(x,joe) cout << x << " ";

    vector<bool> visited2(n+1,false);
    vector<int> mama;
    dfs(v,0,adj,visited2,joe,mama);

    // each(x,mama) cout << x << "\n";
    sort(all(mama));
    if (mama.size() > 1 && mama.back() <= k) {
        cout << "YES\n";
    }
    else {
        cout << "NO\n";
    }
}

int main() 
{ 
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) solve();
	
    return 0; 
} 
