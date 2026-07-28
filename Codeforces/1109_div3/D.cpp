#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n,m; cin >> n >> m;
        vector<long long> a(n);
        for (long long& i : a) cin >> i;
        vector<int> b(m);
        for (int& i : b) {
            cin >> i;
            i--;
        }
        vector<long long> pos_pre(n);
        vector<long long> neg_pre(n);
        for (int i = 0; i < n; ++i) {
            if (a[i] > 0) pos_pre[i] = a[i];
            else neg_pre[i] = abs(a[i]);
            if (i > 0) {
                pos_pre[i] += pos_pre[i-1];
                neg_pre[i] += neg_pre[i-1];
            }
        }
        sort(b.rbegin(),b.rend());
        int sz = b.size();
        long long res = pos_pre[n-1] - pos_pre[b[0]] - (neg_pre[n-1] - neg_pre[b[0]]);
        bool tog = true; // true when pos is pos, false when pos is neg
        for (int i = 0; i < sz; ++i) {
            if (i == sz-1) {
                long long pos = pos_pre[b[i]], neg = neg_pre[b[i]];
                if (tog) swap(pos,neg);
                if (tog) {
                    if (pos > neg) {
                        res += pos - neg;
                    }
                    else {
                        res += neg - pos;
                    }
                }
                else {
                    if (neg > pos) {
                        res += neg - pos;
                    }
                    else {
                        res += pos - neg;
                    }
                }
                break;
            }
            else {
                long long pos = pos_pre[b[i]] - pos_pre[b[i+1]];
                long long neg = neg_pre[b[i]] - neg_pre[b[i+1]];
                if (tog) {
                    if (pos > neg) {
                        res += pos - neg;
                        tog = !tog;
                    }
                    else {
                        res += neg - pos;
                    }
                }
                else {
                    if (neg > pos) {
                        res += neg - pos;
                        tog = !tog;
                    }
                    else {
                        res += pos - neg;
                    }
                }
            }
        }
        cout << res << '\n';
    }
}