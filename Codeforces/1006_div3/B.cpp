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
        int n; cin >> n;
        string s; cin >> s;
        long long joe = count(s.begin(),s.end(),'-');
        long long mama = count(s.begin(),s.end(),'_');
        long long left = ceil((long double)(joe)/2);
        long long right = floor((long double)(joe)/2);
        long long res = left*right*mama;
        cout << res << '\n';
    }
    return 0;
}