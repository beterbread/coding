// https://cp-algorithms.com/geometry/area-of-simple-polygon.html
// Template to find area of simple polygon in O(n)
// Simple polygon has no self intersection

#include <bits/stdc++.h> 
using namespace std; 

struct point {
    int x, y;
    point(int x, int y) : x(x), y(y) {};
};

double area(const vector<point>& fig) {
    double res = 0;
    for (unsigned i = 0; i < fig.size(); i++) {
        point p = i ? fig[i - 1] : fig.back();
        point q = fig[i];
        res += (p.x - q.x) * (p.y + q.y);
    }
    return fabs(res) / 2;
}

double area(const vector<vector<int>>& fig) {
    double res = 0;
    for (unsigned i = 0; i < fig.size(); i++) {
        auto p = i ? fig[i - 1] : fig.back();
        auto q = fig[i];
        res += (p[0] - q[0]) * (p[1] + q[1]);
    }
    return fabs(res) / 2;
}

int main() {
    // Points in struct form
    point p1 = point(1, 2);
    point p2 = point(4, 5);
    point p3 = point(10, 21);
    vector<point> fig1;
    fig1.push_back(p1);
    fig1.push_back(p2);
    fig1.push_back(p3);
    cout << area(fig1) << "\n";
    
    // Points in vector form
    vector<int> p4 = {1, 2};
    vector<int> p5 = {4, 5};
    vector<int> p6 = {10, 21};
    vector<vector<int>> fig2;
    fig2.push_back(p4);
    fig2.push_back(p5);
    fig2.push_back(p6);
    cout << area(fig2) << "\n";

    return 0;
}