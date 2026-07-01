#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> h(n);
        for (int& i : h) cin >> i;
        cout << *max_element(h.begin(),h.end())-*min_element(h.begin(),h.end())+1 << '\n';
    }
}
