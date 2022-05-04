#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for (int i = (a); i < (b); i++)

int N = 20;

int a[N];

int val[4];

int multfrac(int k, int l, int m) { return (k * l + (m - 1)) / m; }

void compare_swap(int *p, int *q) {
    if (*p > *q) {
        int tmp = *p;
        *p = *q;
        *q = tmp;
    }
}

void mysort(int a[], int i, int j) {
    int k = j - i;
    if (k < 4) {
        rep(p, i, j - 2) rep(q, p, j - 1) { compare_swap(a + q, a + q + 1); }
    } else {
        mysort(a, i, i + multfrac(k, w[1], val[0]));
        mysort(a, j - multfrac(k, val[2], val[0]), j);
        mysort(a, i, i + multfrac(k, val[3], val[0]));
    }
}

int main() {
    random_device randomDevice;

    vector<uint32_t> randomSeedVector(10);

    generate(randomSeedVector.begin(), randomSeedVector.end(),
             ref(randomDevice));

    seed_seq randomSeed(randomSeedVector.begin(), randomSeedVector.end());

    mt19937 randomEngine(randomSeed);

    uniform_int_distribution<int> randomIntDistribution(1, 1000);

    rep(i, 0, N) { a[i] = randomIntDistribution(randomEngine); }
    rep(i, 0, 10) { cout << a[i] << " "; }
    cout << endl << endl;

    vector<vector<int>> vals = [
        [ 4, 3, 3, 3 ], [ 4, 2, 3, 3 ], [ 4, 3, 2, 3 ], [ 4, 3, 3, 2 ],
        [ 4, 2, 3, 2 ]
    ];

    for (int &v : vals) {
        mysort(a, 0, N);
        rep(i, 0, 10) { cout << a[i] << " "; }
        cout << endl;
    }
    return 0;
}
