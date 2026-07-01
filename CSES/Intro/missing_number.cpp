#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    vector<int> a(n-1);
    for (int& i : a) cin >> i;
    unordered_set<int> set(a.begin(),a.end());
    for (int i = 1; i <= n; i++) {
        if (set.find(i) == set.end()) {
            cout << i << '\n';
            break;
        }
    }
    return 0;
}