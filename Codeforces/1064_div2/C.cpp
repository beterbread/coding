#include <bits/stdc++.h> 
using namespace std; 

using ll = long long;
using ull = unsigned long long;
using ld = long double;
const ll MOD = 1e9 + 7;
const ll INF = 1e18;
const int INF_INT = 1e9;
const ld EPS = 1e-9;
#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr);
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
#define ff first
#define ss second
#define each(x, a) for (auto &x : a)                    
#define FOR(i, n) for (int i = 0; i < (n); ++i)           
#define FORD(i, n) for (int i = (n) - 1; i >= 0; --i)   
#define clz(x) __builtin_clz(x)
#define ctz(x) __builtin_ctz(x)
#define popcount(x) __builtin_popcount(x)
#define parity(x) __builtin_parity(x)
#define clzll(x) __builtin_clzll(x)
#define ctzll(x) __builtin_ctzll(x)
#define popcountll(x) __builtin_popcountll(x)
#define parityll(x) __builtin_parityll(x)

struct Node {
    int val;
    Node* next;
    Node* prev;

    Node(int val, Node* next, Node* prev) {
        this->val = val;
        this->next = next;
        this->prev = prev;
    }
};

void remove(Node* node) {
    Node* next_tmp = node->next;
    Node* prev_tmp = node->prev;

    delete node;
    prev_tmp->next = next_tmp;
    next_tmp->prev = prev_tmp;
}

void solve() {
    int n;
    cin >> n;
    vector<Node*> a(n);
    FOR(i, n) { 
        int num;
        cin >> num;
        a[i] = new Node(num, nullptr, nullptr);
    }

    priority_queue<pair<int, Node*>, vector<pair<int, Node*>>, greater<pair<int, Node*>>> pq;
    FOR(i, n) {
        a[i]->prev = i == 0 ? a[n - 1] : a[i - 1];
        a[i]->next = i == n - 1 ? a[0] : a[i + 1];
        pq.push({a[i]->val, a[i]});
    }
    
    ll res = 0;
    while (pq.size() >= 3) {
        Node* node = pq.top().ss;
        pq.pop();
        res += min(node->prev->val, node->next->val);
        remove(node);
    }
    // Remaining two nodes
    Node* node = pq.top().ss;
    res += max(node->val, node->next->val);

    cout << res << endl;
}

int main() 
{ 
	fast_io

	int t;
    cin >> t;
    while (t--) {
        solve();
    }
	
	return 0; 
} 
