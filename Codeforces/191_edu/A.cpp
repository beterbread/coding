#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n,x,y,z; cin >> n >> x >> y >> z;
        int pos = ceil(double(n)/double(x+y)); 
        int pos2 = ceil(double(n)/double(x));
        pos2 = min(pos2,z);
        n = max(0,n-(x*z));
        if (n > 0) {
            pos2 += ceil(double(n)/double(x+(10*y)));
        }
        cout << min(pos,pos2) << '\n';
    }
}