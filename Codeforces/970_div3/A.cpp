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
    int tc; cin >>tc;
    while (tc--) {
        int a,b; cin >>a>>b;
        int res = 0;
        if (b&1) res+=2;
        if (a>1 && res==2) {
            res-=2;
            a-=2;
        }
        cout << (res==0 && !(a&1) ? "YES" : "NO") << "\n";
    }
    
    return 0;
}