#include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/cpp/lambda-expression-in-c/

int main() {
    // syntax: [](int a) -> int{return a-1;};
    // Generally, we don't need to specify the return type explicitly
    // Capture clause:
    // [&] capture all external variables by reference
    // [=] capture all external variables by value
    // [a,&b] capture a by value and b by reference
    // [] empty clause means lambda can only use variables local to it

    auto res = [](int x) {
        return x + x;
    };
    cout << res(5);

    // useful for custom comparators
    vector<int> v = {5, 1, 8, 3, 9, 2};
    sort(v.begin(), v.end(), [] (const int& a, const int&b) {
		return a > b;
	});

    return 0;
}