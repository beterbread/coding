#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    long long k,x; cin >> k >> x;
    vector<long long> a(n);
    for (long long& i : a) cin >> i;
    sort(a.begin(),a.end());
    vector<bool> joe(n-1,true);
    priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> pq;
    for (int i = 0; i < n-1; ++i) {
        long long diff = a[i+1]-a[i];
        if (diff > x) {
            joe[i] = false;
            long long mama = ceil((long double)(diff)/(long double)(x)-1);
            if (mama < 0) mama = 0;
            pq.push({mama,i});
        }
    }
    while (!pq.empty()) {
        auto [ops,i] = pq.top(); pq.pop();
        if (ops > k) break;
        k -= ops;
        joe[i] = true;
    }
    cout << count(joe.begin(),joe.end(),false)+1 << '\n';
}
