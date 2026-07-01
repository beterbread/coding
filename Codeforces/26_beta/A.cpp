//https://codeforces.com/contest/26/problem/A

#include <bits/stdc++.h>
using namespace std;

int almostPrime(int n) {
    vector<pair<bool, int>> isPrime(n + 1, {true, 0});
    for (int i = 2; i <= n; i++) {
        if (isPrime[i].first) {
            for (int j = i + i; j <= n; j += i) {
                isPrime[j].first = false;
                isPrime[j].second += 1;
            }
        }
    }
    int res = 0;
    for (int i = 2; i <= n; i++) {
        if (isPrime[i].second == 2) res++;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    cout << almostPrime(n) << endl;
}