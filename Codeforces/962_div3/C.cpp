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

void solve() {
    // sorted = same freq of chars
    // prefix of freq of chars?
    // res = min need to transform a->b or b->a
    int n,q; cin >> n >> q;
    string a,b; cin >> a >> b;
    vector<vector<int>> pre_a(n,vector<int>(26,0));
    vector<vector<int>> pre_b(n,vector<int>(26,0));
    FOR(i,n) {
        pre_a[i][a[i]-'a']++;
        pre_b[i][b[i]-'a']++;
        if (i>0) {
            FOR(j,26) {
                pre_a[i][j]+=pre_a[i-1][j];
                pre_b[i][j]+=pre_b[i-1][j];
            }
        }
    }
    int freq_a[26], freq_b[26];
    while (q--) {
        int l,r; cin >> l >> r;
        l--; r--; // zero indexing
        memset(freq_a,0,sizeof(freq_a));
        memset(freq_b,0,sizeof(freq_b));
        FOR(i,26) {
            freq_a[i]=pre_a[r][i];
            freq_b[i]=pre_b[r][i];
            if (l>0) {
                freq_a[i]-=pre_a[l-1][i];
                freq_b[i]-=pre_b[l-1][i];
            }
        }
        int pos1=0, pos2=0;
        FOR(i,26) {
            if (freq_a[i]>freq_b[i]) {
                pos1+=freq_a[i]-freq_b[i];
            }
            else if (freq_b[i]>freq_a[i]) {
                pos2+=freq_b[i]-freq_a[i];
            }
        }
        cout << min(pos1,pos2) << '\n';
    }
}

int main() 
{ 
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) solve();
    return 0; 
} 
