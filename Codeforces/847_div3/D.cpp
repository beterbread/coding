#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int& i : a) cin >> i;
        map<int,int> map;
        for (const int& i : a) map[i]++;
        int res = 0;
        while (!map.empty()) {
            res++;
            int joe = map.begin()->first;
            map.begin()->second--;
            if (map.begin()->second == 0) map.erase(map.begin());
            while (map.find(joe+1) != map.end()) {
                joe++;
                if (--map[joe] == 0) map.erase(joe);
            }
        }
        cout << res << '\n';
    }
}
