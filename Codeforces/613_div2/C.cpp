#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    long long x; cin >> x;
    long long a = LLONG_MAX, b = LLONG_MAX;
    for (long long i = 1; i <= sqrt(x); ++i) {
        if (x % i == 0) {
            if (lcm(i,x/i) == x && min(i,x/i) < max(a,b)) {
                a = i, b = x/i;
            }
        }
    }
    cout << a << ' ' << b << '\n';
}
