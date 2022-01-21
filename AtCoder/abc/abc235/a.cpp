#include <bits/stdc++.h>

#include <atcoder/all>

using namespace std;
using namespace atcoder;

#define rep(i, a, b) for (int i = (a); i < (b); i++)

int main() {
    vector<int> b;
    rep(i, 0, 3) cin >> b[i];
    int ans = b[0] + b[1] + b[2];
    cout << 111 * ans << endl;
    return 0;
}