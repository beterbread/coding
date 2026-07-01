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

class MedianFinder {
public:
    priority_queue<int> left;
    priority_queue<int, vector<int>, greater<int>> right;
    MedianFinder() {
        left = {};
        right = {};
    }
    
    void addNum(int num) {
        if (left.empty() || num <= left.top()) {
            left.push(num);
        } 
        else {
            right.push(num);
        }
        // Ensure left has at most one more element if size not equal
        if (left.size() > right.size() + 1) {
            right.push(left.top());
            left.pop();
        } 
        else if (right.size() > left.size()) {
            left.push(right.top());
            right.pop();
        }
    }
    
    int findMedian() {
        return left.top();
    }
};

void solve() {
    int x; cin >> x;
    int q; cin >> q;
    MedianFinder joe = MedianFinder();
    joe.addNum(x);
    while (q--) {
        int a,b; cin >> a >> b;
        joe.addNum(a);
        joe.addNum(b);
        cout << joe.findMedian() << '\n';
    }
}

int main() 
{ 
    cin.tie(0)->sync_with_stdio(0);
    solve();
    return 0; 
} 
