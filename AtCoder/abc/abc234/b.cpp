#include <bits/stdc++.h>

#include <atcoder/all>

using namespace std;
using namespace atcoder;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

template <typename T>
bool chmax(T& a, const T& b) {
    if (a < b) {
        a = b;  // aをbで更新
        return true;
    }
    return false;
}

int main() {
    int n;
    vector<pair<int, int>> S(n);
    double ans = 0;
    cin >> n;
    rep(i, n) { cin >> S[i].first >> S[i].second; }
    rep(i, n) rep(j, n) {
        chmax(ans, sqrt(pow(S[i].first - S[j].first, 2) +
                        pow(S[i].second - S[j].second, 2)));
    }

    cout << fixed << ans << setprecision(10) << endl;
    return 0;
}