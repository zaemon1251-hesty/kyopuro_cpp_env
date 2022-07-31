#include <bits/stdc++.h>

#include <atcoder/modint>
using namespace std;
using namespace atcoder;
using mint = modint998244353;

int main() {
    int N;
    cin >> N;

    vector<int> a(N);
    for (int i = 0; i < N; i++) cin >> a[i];

    mint ans = 0;

    for (int i = 1; i <= N; i++) {
        vector dp(N + 1, vector(i + 1, vector<mint>(i, 0)));
        dp[0][0][0] = 1;
        for (int j = 0; j < N; j++) {
            for (int k = 0; k <= i; k++) {
                for (int l = 0; l < i; l++) {
                    dp[j + 1][k][l] += dp[j][k][l];
                    if (k != i) dp[j + 1][k + 1][(l + a[j]) % i] += dp[j][k][l];
                }
            }
        }
        ans += dp[N][i][0];
    }

    cout << ans.val() << endl;

    return 0;
}
