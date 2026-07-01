#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
 
template<class T>
using ordered_set =
tree<T, null_type, less<T>, rb_tree_tag,
tree_order_statistics_node_update>;

int main() {
    ordered_set<int> set;
    // all operations are log(n)
    s.insert(x);          // insert
    s.erase(x);           // erase
    s.find(x);            // iterator to x
    s.order_of_key(x);    // count of elements < x
    s.find_by_order(k);   // iterator to k-th element (0-indexed)
    return 0;
}