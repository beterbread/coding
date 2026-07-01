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
        int n,k,p; cin >> n >> k >> p;
        k = abs(k);
        if (k==0) {
            cout << "0\n";
            continue;
        }
        if (n*p < k) {
            cout << "-1\n";
            continue;
        }
        cout << ceil(double(k)/double(p)) << '\n';
    }
    return 0;
}