#include <bits/stdc++.h>

#include <atcoder/all>

using namespace std;
using namespace atcoder;

string toBinary(uint64_t n) {
    string r;
    int i = 0;
    while (n != 0) {
        i++;
        r += (n % 2 == 0 ? "0" : "2");
        n /= 2;
    }
    return r;
}

int main() {
    uint64_t k;
    cin >> k;
    string s = toBinary(k);
    reverse(s.begin(), s.end());
    cout << s << endl;
    return 0;
}