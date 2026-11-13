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

void solve() {
    string s1,s2; cin >> s1 >> s2;
    int t,q; cin >> t >> q;
    queue<pair<int,int>> blocked; // time, pos
    unordered_set<int> blockedSET;
    int n = s1.size();
    vector<int> a(n);
    FOR(i,n) {
        a[i] = s1[i] == s2[i];
    }
    FT ft(n);
    ft.build(a);
    FOR(i,q) {
        int type; cin >> type;
        if (!blocked.empty() && blocked.front().ff == i) {
            auto [trash,pos] = blocked.front();
            blocked.pop();
            if (s1[pos] != s2[pos]) {
                if (ft.range_query(pos,pos) == 1) {
                    ft.update(pos,-1);
                }
            }
            blockedSET.erase(pos);
        }
        if (type == 1) {
            int pos; cin >> pos; 
            pos--;
            if (ft.range_query(pos,pos) == 0) {
                ft.update(pos,1);
            }
            blocked.push({i+t,pos});
            blockedSET.insert(pos);
        }
        else if (type == 2) {
            int num1,pos1,num2,pos2; cin >> num1 >> pos1 >> num2 >> pos2;
            pos1--;
            pos2--;
            if (num1 == num2) {
                if (num1 == 1) {
                    swap(s1[pos1],s1[pos2]);
                }
                else {
                    swap(s2[pos1],s2[pos2]);
                }
            }
            else {
                if (num1 == 1) {
                    swap(s1[pos1],s2[pos2]);
                }
                else {
                    swap(s2[pos1],s1[pos2]);
                }
            }
            if (s1[pos1] == s2[pos1] && ft.range_query(pos1,pos1) == 0) {
                ft.update(pos1,1);
            }
            else if (s1[pos1] != s2[pos1] && ft.range_query(pos1,pos1) == 1 && blockedSET.find(pos1) == blockedSET.end()) {
                ft.update(pos1,-1);
            }
            if (s1[pos2] == s2[pos2] && ft.range_query(pos2,pos2) == 0) {
                ft.update(pos2,1);
            }
            else if (s1[pos2] != s2[pos2] && ft.range_query(pos2,pos2) == 1 && blockedSET.find(pos2) == blockedSET.end()) {
                ft.update(pos2,-1);
            }
        }
        else {
            cout << (ft.range_query(0,n-1) == n ? "YES" : "NO") << '\n';
        }
    }
}

int main() 
{ 
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) solve();
    return 0; 
} 
