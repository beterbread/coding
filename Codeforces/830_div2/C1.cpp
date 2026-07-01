#include <bits/stdc++.h> 
using namespace std; 

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
#define ff first
#define ss second
#define each(x, a) for (auto &x : a)                    
#define FOR(i, n) for (int i = 0; i < (n); ++i)           
#define FORD(i, n) for (int i = (n) - 1; i >= 0; --i)   

struct ST {
    int n;
    vector<long long> tree;
    int type; 
    // type 0 = sum
    // type 1 = min
    // type 2 = max
    // type 3 = gcd
    // type 4 = xor

    long long merge(long long a, long long b) const {
        if (type == 0) return a + b;
        if (type == 1) return min(a, b);
        if (type == 2) return max(a, b);
        if (type == 3) return gcd(a, b);
        if (type == 4) return a ^ b;
        return 0; 
    }

    long long identity() const {
        if (type == 0) return 0;
        if (type == 1) return LLONG_MAX;
        if (type == 2) return LLONG_MIN;
        if (type == 3) return 0;
        if (type == 4) return 0;    
        return 0;
    }

    ST(int n, int type) : n(n), tree(4 * n), type(type) {}

    void build(const vector<int>& A, int node, int l, int r) {
        if (l == r) {
            tree[node] = A[l];
            return;
        }
        int mid = (l + r) / 2;
        build(A, 2 * node, l, mid);
        build(A, 2 * node + 1, mid + 1, r);

        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }

    void build(const vector<int>& A) { build(A, 1, 0, n - 1); }

    long long query(int node, int l, int r, int ql, int qr) const {
        if (qr < l || ql > r) return identity();
        if (ql <= l && r <= qr) return tree[node];
        int mid = (l + r) / 2;
        return merge(
            query(2 * node, l, mid, ql, qr),
            query(2 * node + 1, mid + 1, r, ql, qr)
        );
    }

    long long query(int l, int r) const { return query(1, 0, n - 1, l, r); }

    void update(int node, int l, int r, int idx, long long val) {
        if (l == r) {
            tree[node] = val;
            return;
        }
        int mid = (l + r) / 2;
        if (idx <= mid)
            update(2 * node, l, mid, idx, val);
        else
            update(2 * node + 1, mid + 1, r, idx, val);
        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }

    void update(int idx, long long val) { update(1, 0, n - 1, idx, val); }
};

void solve() {
    int n,q; cin >> n >> q;
    vector<int> a(n);
    FOR(i,n) cin >> a[i];
    int L,R; cin >> L >> R;
    ST st_sum(n,0); st_sum.build(a);
    ST st_xor(n,4); st_xor.build(a);
    auto f = [&](int l, int r) -> ll {
        return st_sum.query(l,r) - st_xor.query(l,r);
    };
    int l=-1, r=-1;
    ll res = INT_MIN;
    FOR(i,n) {
        for (int j = i; j < n; j++) {
            ll pos = f(i,j);
            if (pos == res) {
                if (j-i+1 < r-l+1) {
                    l = i;
                    r = j;
                }
            }
            else if (pos > res) {
                res = pos;
                l = i;
                r = j;
            }
        }
    }
    cout << l+1 << ' ' << r+1 << '\n';
}

int main() 
{ 
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) solve();
    return 0; 
} 
