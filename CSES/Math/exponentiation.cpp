#include <bits/stdc++.h>
using namespace std;

const int m = 1e9+7;
long long modexp(long long a, long long b) {
    a %= m;
    long long res = 1;
    while (b) {
        if (b&1) {
            res = res * a % m;
        }
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    while (n--) {
        long long a,b; cin >> a >> b;
        cout << modexp(a,b) << '\n';
    }
    return 0;
}