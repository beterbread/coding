/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

// #include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    // std::cout<<"Hello World";
    cin.tie(0)->sync_with_stdio(0);
    int tc; cin >> tc;
    while (tc--) {
        long long n,x; cin >> n >> x;
        if (n==1) {
            cout << x << '\n';
            continue;
        }
        long long joe = 0;
        for (int i = 0; i < n-1; i++) {
            joe |= i;
            cout << i << ' ';
        }
        // cout << joe << '\n';
        if ((n-1)||joe == x) {
            cout << n-1 << '\n';
            continue;
        }
        long long last = 0;
        for (int i = 0; i < 31; i++) {
            if (joe&(1<<i)) {
                if (!(x&(1<<i))) last |= (1<<i);
            }
            else {
                if (x&(1<<i)) last |= (1<<i);
            }
        }
        cout << last << '\n';
    }
    return 0;
}