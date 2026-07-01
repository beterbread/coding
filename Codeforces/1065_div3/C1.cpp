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
#define rep(i, a, b) for (int i = (a); i < (b); ++i)       
#define repd(i, a, b) for (int i = (a); i >= (b); --i)    
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

int score(vector<int>& count) { // For A_count and B_count
    return count[1] % 2;
}

void solve() {
    int n;
    cin >> n;
    vector<int> A(n); // Ajisai
    vector<int> B(n); // Mai
    vector<int> A_count(2, 0);
    vector<int> B_count(2, 0);
    FOR(i, n) {
        cin >> A[i];
        if (A[i] == 0) {
            A_count[0]++;
        }
        if (A[i] == 1) {
            A_count[1]++;
        }
    }
    FOR(i, n) {
        cin >> B[i]; 
        if (B[i] == 0) {
            B_count[0]++;
        }
        if (B[i] == 1) {
            B_count[1]++;
        }
    }
    FOR(i, n) {
        if (A[i] == B[i]) continue; // No point in swapping same element
        // Optimal if swap gives player XOR score of 1
        if ((i + 1) % 2 == 1) { // Ajisai's turn
            if (A[i] == 0 && B[i] == 1) {
                A_count[1]++;
                A_count[0]--;
                if (score(A_count) == 1) { // Finalize swap
                    B_count[1]--;
                    B_count[0]++;
                }
                else { // Don't swap
                    A_count[1]--;
                    A_count[0]++;
                }
            }
            else {
                A_count[1]--;
                A_count[0]++;
                if (score(A_count) == 1) { // Finalize swap
                    B_count[1]++;
                    B_count[0]--;
                }
                else { // Don't swap
                    A_count[1]++;
                    A_count[0]--;
                }
            }
        }
        else { // Mai's turn
            if (B[i] == 0 && A[i] == 1) {
                B_count[1]++;
                B_count[0]--;
                if (score(B_count) == 1) { // Finalize swap
                    A_count[1]--;
                    A_count[0]++;
                }
                else { // Don't swap
                    B_count[1]--;
                    B_count[0]++;
                }
            }
            else {
                B_count[1]--;
                B_count[0]++;
                if (score(B_count) == 1) { // Finalize swap
                    A_count[1]++;
                    A_count[0]--;
                }
                else { // Don't swap
                    B_count[1]++;
                    B_count[0]--;
                }
            }
        }
    }
    int A_score = score(A_count);
    int B_score = score(B_count);
    if (A_score == B_score) {
        cout << "Tie\n";
    }
    else {
        if (A_score == 1) cout << "Ajisai\n";
        else cout << "Mai\n";
    }
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
