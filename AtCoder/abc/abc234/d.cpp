#include <bits/stdc++.h>

#include <atcoder/all>

using namespace std;
using namespace atcoder;
#define rep(i, a, b) for (int i = (a); i < (b); i++)

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> p(n);
    set<int> s;
    rep(i, 0, n) cin >> p[i];
    rep(i, 0, k) s.insert(p[i]);
    cout << *s.begin() << endl;
    rep(i, k, n) {
        if (*s.begin() < p[i]) {
            s.erase(s.begin());
            s.insert(p[i]);
        }
        cout << *s.begin() << endl;
    }
    return 0;
}