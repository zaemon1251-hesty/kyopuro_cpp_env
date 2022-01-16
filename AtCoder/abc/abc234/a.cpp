#include <bits/stdc++.h>

#include <atcoder/all>

using namespace std;
using namespace atcoder;

int f(int x) { return x * x + 2 * x + 3; }

int main() {
    int t;
    cin >> t;
    cout << f(f(f(t) + t) + f(f(t))) << endl;
    return 0;
}
