#include <bits/stdc++.h>
using namespace std;

// A binary indexed tree or Fenwick tree can be seen 
// as a dynamic variant of a prefix sum array
// It supports two O(log(n)) time operations on an array:
// processing a range sum query
// and updating a value

/* FENWICK TREE - O(n * log(n)) build, O(log(n)) query, O(log(n)) update */
struct FT {
    int n;
    vector<long long> bit;

    FT(int n) {
        this->n = n + 1;
        bit.assign(this->n, 0);
    }

    void update(int idx, long long val) {
        for (++idx; idx < n; idx += idx & -idx)
            bit[idx] += val;
    }

    long long query(int idx) const {
        long long sum = 0;
        for (++idx; idx > 0; idx -= idx & -idx)
            sum += bit[idx];
        return sum;
    }

    long long range_query(int l, int r) const {
        return query(r) - query(l - 1);
    }

    void build(const vector<int>& A) {
        for (int i = 0; i < (int)A.size(); i++)
            update(i, A[i]);
    }
};

int main() {
    vector<int> A = {1, 3, 4, 8, 6, 1, 4, 2};
    int n = A.size();

    FT ft(n);
    ft.build(A);
 
    cout << "Sum [3, 6] = " << ft.range_query(3, 6) << "\n"; // 8 + 6 + 1 + 4 = 19
    cout << "Sum [0, 3] = " << ft.range_query(0, 3) << "\n"; // 1 + 3 + 4 + 8 = 16

    ft.update(2, 6); // add 6 + A[2] = 10
    cout << "After update, Sum [0, 3] = " << ft.range_query(0, 3) << "\n"; // 1 + 3 + 10 + 8 = 22

    return 0;
}