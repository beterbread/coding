#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int& i : a) cin >> i;
        int div5=0, divjoe=0;
        for (const int& x : a) {
            if (x%5==0) div5++;
            else divjoe++;
        }
        if (div5 > 0 && divjoe > 0) {
            cout << "No\n";
            continue;
        }
        if (div5 == n) {
            sort(a.begin(),a.end());
            int check1 = 0, check2 = 0;
            for (int i = 0; i < n; ++i) {
                if ((a[i]+(a[i]%10) == a[n-1])) check1++;
                if (a[i] == a[n-1]) check2++;
            }
            cout << ((check1==n || check2==n) ? "Yes" : "No") << '\n';
            continue;
        }
        // else none are div by 5
        for (int& x : a) {
            while (!(x%10==2)) {
                x += x%10;
            }
            x %= 20;
        }
        bool res = true;
        for (int i = 0; i < n-1; ++i) {
            if (a[i] != a[i+1]) {
                res = false;
                break;
            }
        }
        cout << (res ? "Yes" : "No") << '\n';
    }
}