#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    unordered_set<string> set;
    for (int i = 0; i < n; ++i) {
        int m; cin >> m;
        bool found = false;
        for (int j = 0; j < m; ++j) {
            string s; cin >> s;
            if (s.find("bie") != string::npos && set.find(s) == set.end()) {
                set.insert(s);
                found = true;
                cout << s << '\n';
            }
        }
        if (!found) {
            cout << "Time to play Genshin Impact, Teacher Rice!\n";
        }
    }
}
