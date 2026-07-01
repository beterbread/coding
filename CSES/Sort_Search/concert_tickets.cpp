#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n,m; cin >> n >> m;
    multiset<int> set;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        set.insert(x);
    }
    for (int i = 0; i < m; i++) {
        int x; cin >> x;
        if (set.empty()) {
            cout << "-1\n";
            continue;
        }
        auto it = set.lower_bound(x);
        if (it == set.end()) {
            cout << *prev(set.end()) << '\n';
            set.erase(prev(set.end()));
        }
        else if (*it != x) {
            if (it == set.begin()) {
                cout << "-1\n";
            }
            else {
                cout << *prev(it) << '\n';
                set.erase(prev(it));
            }
        }
        else {
            cout << *it << '\n';
            set.erase(it);
        }
    }
    return 0;
}