#include <bits/stdc++.h>
using namespace std;

// CHICKEN MCNUGGET THEOREM

int main() {
    cin.tie(0)->sync_with_stdio(0);
    unordered_set<int> set;
    for (int i = 0; i <= 100; ++i) {
        for (int j = 0; j <= 10; ++j) {
            int joe = (i*11)+(j*111);
            set.insert(joe);
        }
    }
    int t; cin >> t;
    while (t--) {
        int x; cin >> x;
        if (x <= 1099) {
            cout << (set.find(x) != set.end() ? "YES" : "NO") << '\n';
        }
        else {
            cout << "YES\n";
        }
    }
}
