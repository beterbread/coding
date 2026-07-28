#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<vector<int>> adj(n+1);
        for (int i = 2; i <= n; ++i) {
            int par; cin >> par;
            adj[par].push_back(i);
        }
        vector<int> leaf(n+1);
        for (int i = 1; i <= n; ++i) {
            cin >> leaf[i];
            sort(adj[i].begin(),adj[i].end());
        }
        auto solve = [&](int x, auto&& solve) -> tuple<int,int,bool> {
            if (leaf[x]) {
                return {leaf[x],leaf[x],true};
            }
            bool is_ok = true;
            vector<tuple<int,int,bool>> joe;
            for (int y : adj[x]) {
                joe.push_back(solve(y,solve));
                auto [a,b,c] = joe[joe.size()-1];
                if (get<2>(joe[joe.size()-1]) == false) {
                    is_ok = false;
                    break;
                }
            }
            if (!is_ok) {
                return {-1,-1,false};
            }
            int bad = 0;
            int sz = joe.size();
            tuple<int,int,bool> res = {get<0>(joe[sz-1]),get<1>(joe[sz-1]),true};
            for (int i = 0; i < sz-1; ++i) {
                auto [mn,mx,ok] = joe[i];
                auto [mn2,mx2,ok2] = joe[i+1];
                get<0>(res) = min(get<0>(res),mn);
                get<1>(res) = max(get<1>(res),mx);
                if (mn > mn2 || mx > mn2) {
                    bad++;
                }
            }
            if (sz > 1 && (get<0>(joe[sz-1]) > get<0>(joe[0]) || get<1>(joe[sz-1]) > get<0>(joe[0]))) {
                bad++;
            }
            if (bad > 1) {
                return {-1,-1,false};
            }
            return res;
        };
        if (get<2>(solve(1,solve)) == true) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
}