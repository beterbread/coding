#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n),b(n);
        for (int& i : a) cin >> i;
        for (int& i : b) cin >> i;
        int res = 1;
        for (int i = 0; i < n; i++) {
            res += max(a[i]-b[i],0);
        }
        cout << res << "\n";
    }
    return 0;
}