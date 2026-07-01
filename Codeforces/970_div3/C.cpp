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
    unordered_map<int,int> memo;
    while (tc--) {
        int l,r; cin >>l>>r;
        
        if (memo.find(r-l)!=memo.end()) {
            cout << memo[r-l] << "\n";
            continue;
        }
        int res = 0;
        for (int i = 0; i <= 50000; i++) {
            int sum = i*(i+1)/2;
            if (sum > r-l) break;
            res = i+1;
        }
        memo[r-l]=res;
        cout << res << "\n";
    }
    
    return 0;
}