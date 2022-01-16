#include <bits/stdc++.h>

#include <atcoder/modint>

using namespace std;
using mint = atcoder::modint998244353;

using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n, d;
    cin >> n >> d;
    vector<int> a(n);
    for (auto &v : a) {
        cin >> v;
        --v;
    }

    vector dp(n + 1, vector(1 << d + d + 1, mint(0)));
    dp[0][(1 << d + 1) - 1] = 1;
    for (int i = 0; i < n; ++i) {
        for (int set = 1; set < (1 << d + d + 1); set += 2) {
            const int newSet = set >> 1;
            for (int j = 0; j < d + d + 1; ++j) {
                if (a[i] >= 0 && a[i] != i + j - d) continue;
                if (~newSet >> j & 1) dp[i + 1][newSet | 1 << j] += dp[i][set];
            }
        }
    }

    // rep(i, n + 1) {
    //     rep(j, 1 << d + d + 1) { cout << dp[i][j].val() << " "; }
    //     cout << endl;
    // }

    cout << dp[n][(1 << d + 1) - 1].val() << endl;
    return 0;
}
