#include <bits/stdc++.h>

#include <atcoder/all>

using namespace std;
using namespace atcoder;
using ll = long long;

#define rep(i, a, b) for (int i = (a); i < (b); i++)

typedef modint998244353 mint;

const ll MAX = 5010, MOD = 998244353;

vector<ll> fac, finv, inv;

void binom_init() {
    fac.resize(MAX);
    finv.resize(MAX);
    inv.resize(MAX);
    fac[0] = fac[1] = 1;
    inv[1] = 1;
    finv[0] = finv[1] = 1;
    for (int i = 2; i < MAX; i++) {
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - MOD / i * inv[MOD % i] % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

ll binom(ll n, ll r) {
    if (n < r || n < 0 || r < 0) return 0;
    return fac[n] * finv[r] % MOD * finv[n - r] % MOD;
}

int main() {
    binom_init();
    string S;
    cin >> S;
    int N = S.size();
    vector<int> freq(26);
    for (auto el : S) freq[el - 'a']++;
    vector<vector<mint>> dp(27, vector<mint>(N + 1));
    dp[0][0] = 1;
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j <= N; j++) {
            for (int k = 0; k <= min(j, freq[i]); k++) {
                dp[i + 1][j] += dp[i][j - k] * binom(j, k);
            }
        }
    }
    mint ans = 0;
    for (int i = 1; i <= N; i++) {
        ans += dp[26][i];
    }
    cout << ans.val() << endl;
}
