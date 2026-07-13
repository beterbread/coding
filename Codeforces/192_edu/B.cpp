#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    int test = 0;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int& i : a) cin >> i;
        bool joe = false;
        int x = 0, y = 0, z = 0;
        int i = 0;
        while (i < n) {
            x += a[i]==1, y += a[i]==2, z += a[i]==3;
            if (x >= y + z) {
                while (n-i > 3 && i+1 < n && a[i+1] == 3 && x > y + z) {
                    z++;
                    i++;
                }
                joe = true;
                break;
            }
            i++;
        }
        if (!joe) {
            cout << "NO\n";
            continue;
        }
        joe = false;
        i++;
        x = 0, y = 0, z = 0;
        while (i < n) {
            x += a[i]==1, y += a[i]==2, z += a[i]==3;
            if (x + y >= z && i+1 < n) {
                joe = true;
                break;
            }
            i++;
        }
        cout << (joe ? "YES" : "NO") << '\n';
    }
}
