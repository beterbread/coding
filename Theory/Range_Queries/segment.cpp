#include <bits/stdc++.h>
using namespace std;

// Segment trees supports two operations:
// processing a range query and updating an array value
// Compared to Fenwick tree, the advantage of a segment tree
// is that it is a more general data structure  

/* SEGMENT TREE - O(n) build, O(log(n)) query, O(log(n)) update */
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

int main() {
    vector<int> A = {1, 3, 4, 8, 6, 1, 4, 2};
    int n = A.size();

    ST st(n, 0);
    st.build(A);

    cout << "Sum [3, 6] = " << st.query(3, 6) << "\n"; // 8 + 6 + 1 + 4 = 19
    cout << "Sum [0, 3] = " << st.query(0, 3) << "\n"; // 1 + 3 + 4 + 8 = 16

    st.update(2, 10); // set A[2] = 10
    cout << "After update, Sum [0, 3] = " << st.query(0, 3) << "\n"; // 1 + 3 + 10 + 8 = 22

    return 0;
}
