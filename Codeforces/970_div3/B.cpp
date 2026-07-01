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
        int n; cin >>n;
        string s; cin >>s;
        
        int sq = sqrt(n);
        if (sq*sq!=n) {
            cout << "No\n";
            continue;
        }
        
        string joe = "";
        string mama = "";
        for (int i = 0; i < sq; i++) joe.push_back('1');
        mama.push_back('1');
        for (int i = 1; i < sq-1; i++) mama.push_back('0');
        mama.push_back('1');
        
        bool ok = true;
        int i = 0;
        for (int r = 0; r < sq; r++) {
            string cur = "";
            for (int c = 0; c < sq; c++) {
                cur.push_back(s[i]);
                i++;
            }
            if (r==0 || r==sq-1) {
                if (cur!=joe) {
                    ok = false;
                    break;
                }
            }
            else {
                if (cur!=mama) {
                    ok = false;
                    break;
                }
            }
        }
        cout << (ok ? "Yes" : "No") << "\n";
    }
    
    return 0;
}