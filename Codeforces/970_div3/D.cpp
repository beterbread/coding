/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

// #include <iostream>
#include <bits/stdc++.h>
using namespace std;

class DSU {
  private:
	vector<int> parents;
	vector<int> sizes;
	vector<int> res;

  public:
	DSU(int size, string s) : parents(size), sizes(size, 1), res(size) {
		for (int i = 1; i < size; i++) {
		    parents[i] = i;
		    res[i] = s[i-1]=='0';
		}
	}

	int find(int x) { 
		if (parents[x] == x) return x;
		parents[x] = find(parents[x]); 
		return parents[x];
	}

	bool unite(int x, int y) {
		int x_root = find(x);
		int y_root = find(y);
		if (x_root == y_root) return false;

		if (sizes[x_root] < sizes[y_root]) swap(x_root, y_root); 
		res[x_root] += res[y_root];
		sizes[x_root] += sizes[y_root];
		parents[y_root] = x_root;
		return true;
	}

	int joe(int x) {
	    return res[find(x)];
	}
};

int main()
{
    // std::cout<<"Hello World";
    int tc; cin >>tc;
    while (tc--) {
        int n; cin >>n;
        vector<int> p(n);
        for (int& i : p) cin >>i;
        string s; cin >>s;
        
        DSU dsu(n+1,s);
        for (int i = 0; i < n; i++) {
            int x = p[i], y = p[p[i]-1];
            dsu.unite(x,y);
        }
        for (int i = 0; i < n; i++) {
            cout << dsu.joe(p[i]) << " ";
        }
        cout << "\n";
    }
    
    return 0;
}