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

bool good[163][163];
int dp[19][2][2][163][163]; // pos, tight, started, sum, rem
// gcd(X,S) == gcd(X%S,S)
// key idea is to fix the digit sum beforehand and track rem % digit sum and make sure sum < digit sum
ll solve(int pos, int tight, int started, int sum, int rem, int S, vector<int>& digit) {
    if (pos==-1) return started && sum==S && good[rem][S];
    if (dp[pos][tight][started][sum][rem]!=-1) return dp[pos][tight][started][sum][rem];
    ll res = 0;
    int limit = tight ? digit[pos] : 9;
    for (int i = 0; i <= limit; i++) {
        int newTight = tight&(i==digit[pos]);
        int newStarted = started || i>0;
        int newSum = sum;
        int newRem = rem;
        if (newStarted) {
            newSum += i;
            if (newSum>S) continue;
            if (newSum + 9*(pos+1) < S) continue; // impossible to reach target sum
            newRem = (rem*10+i)%S;
        }
        res += solve(pos-1,newTight,newStarted,newSum,newRem,S,digit);
    }
    return res;
}

int main() 
{ 
    cin.tie(0)->sync_with_stdio(0);
    ll a,b; cin >> a >> b;
    a--;
    vector<int> digit1,digit2;
    while (a) {
        digit1.push_back(a%10);
        a/=10;
    }
    while (b) {
        digit2.push_back(b%10);
        b/=10;
    }
    FOR(i,163) {
        FOR(j,163) {
            good[i][j] = gcd(i,j)>1;
        }
    }
    ll R = 0;
    for (int S = 2; S <= 9*digit2.size(); S++) {
        memset(dp,-1,sizeof(dp));
        R+=solve(digit2.size()-1,1,0,0,0,S,digit2);
    }
    ll L = 0;
    for (int S = 2; S <= 9*digit1.size(); S++) {
        memset(dp,-1,sizeof(dp));
        L+=solve(digit1.size()-1,1,0,0,0,S,digit1);
    }
    cout << R-L << '\n';
    return 0; 
} 
