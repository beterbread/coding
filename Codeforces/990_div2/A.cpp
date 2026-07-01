#include <bits/stdc++.h>
using namespace std;

int happy(vector<int>& v) {

    int tiles = 0;
    int res = 0;
    for (int i = 0; i < v.size(); i++) {
        tiles += v[i];
        double x = sqrt(tiles) - 1;
        if (x == (int)x && (int)x % 2 == 0) {
            res++;
        }
    }
    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t > 0) {
        t--;
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        cout << happy(v) << "\n";
    }

    return 0;
}