#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n,w; cin >> n >> w;
        vector<int> a(n);
        for (int& i : a) cin >> i;
        unordered_map<int,int> map;
        vector<int> pw(30);
        for (int i = 0; i <= 29; ++i) {
            pw[i] = pow(2,i);
            map[pw[i]] = i;
        }
        vector<int> joe(30,0);
        for (int i = 0; i < n; ++i) joe[map[a[i]]]++;
        int h = 0;
        int mx = w;
        while (1) {
            int cur_w = 0;
            bool found = false;
            for (int i = 29; i >= 0; --i) {
                if (joe[i] > found) found = true;
                int fit = floor((double)(mx-cur_w)/(double)(pw[i]));
                int mn = min(fit,joe[i]);
                long long mama = cur_w + (pw[i] * mn);
                if (mama > w) continue;
                if (cur_w + (pw[i] * mn) <= mx) {
                    cur_w += (pw[i] * mn);
                    joe[i] -= mn;
                }
            }
            if (!found) break;
            h++;
            mx = cur_w;
        }
        cout << h << '\n';
    }
}
