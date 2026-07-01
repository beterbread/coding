#include <bits/stdc++.h>
using namespace std;

// Static array queries
// The array values are never updated between the queries
// It suffices to construct a static data structure
// tells us the answer for any possible query

/* PREFIX SUM - O(n) build, O(1) query */
vector<long long> build_prefix_sum(const vector<int>& A) {
    int n = A.size();
    vector<long long> prefix(n);
    prefix[0] = A[0];
    for (int i = 1; i < n; i++)
        prefix[i] = prefix[i - 1] + A[i];
    return prefix;
}
long long range_sum(const vector<long long>& prefix, int L, int R) {
    return (L == 0) ? prefix[R] : prefix[R] - prefix[L - 1];
}

/* SPARSE TABLE - O(n * log(n)) build, O(1) query */
vector<vector<int>> build_sparse_min(const vector<int>& A) {
    int n = A.size(), LOG = log2(n) + 1;
    vector<vector<int>> st(n, vector<int>(LOG));
    for (int i = 0; i < n; i++) st[i][0] = A[i];
    for (int j = 1; (1 << j) <= n; j++)
        for (int i = 0; i + (1 << j) <= n; i++)
            st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
    return st;
}
vector<vector<int>> build_sparse_max(const vector<int>& A) {
    int n = A.size(), LOG = log2(n) + 1;
    vector<vector<int>> st(n, vector<int>(LOG));
    for (int i = 0; i < n; i++) st[i][0] = A[i];
    for (int j = 1; (1 << j) <= n; j++)
        for (int i = 0; i + (1 << j) <= n; i++)
            st[i][j] = max(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
    return st;
}
int query_min(const vector<vector<int>>& st, int L, int R) {
    int k = log2(R - L + 1);
    return min(st[L][k], st[R - (1 << k) + 1][k]);
}
int query_max(const vector<vector<int>>& st, int L, int R) {
    int k = log2(R - L + 1);
    return max(st[L][k], st[R - (1 << k) + 1][k]);
}

int main() {
    vector<int> A = {1, 3, 4, 8, 6, 1, 4, 2};

    auto prefix = build_prefix_sum(A);
    cout << "Sum [3,6] = " << range_sum(prefix, 3, 6) << "\n";

    auto st_min = build_sparse_min(A);
    auto st_max = build_sparse_max(A);
    cout << "Min [2,6] = " << query_min(st_min, 2, 6) << "\n";
    cout << "Max [2,6] = " << query_max(st_max, 2, 6) << "\n";

    return 0;
}