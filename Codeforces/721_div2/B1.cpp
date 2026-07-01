#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n; 
        string s; cin >> s;
        if (!(n&1)) {
            cout << "BOB\n";
        }
        else {
            if (n==1) {
                cout << (s[0]=='0' ? "BOB" : "DRAW") << '\n';
            }
            else if (n==2) {
                cout << (s[0]!=s[1] ? "BOB" : "DRAW") << '\n';
            }
            else {
                cout << (s[n/2]=='0' && count(s.begin(),s.end(),'0')>1 ? "ALICE" : "BOB") << '\n';
            }
        }
    }
}
