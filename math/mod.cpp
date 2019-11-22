#include <iostream>
#include <math.h>

using namespace std;

typedef long long ll;

#define FOR(i, n, m) for (ll i = (n); i < (m); ++i)

const int MOD = 1000000007;

const int MAX = 1e5+10;

ll fac[MAX<<2];  // fac[n] = n!
ll finv[MAX<<2]; // (fac[n] * finv[n]) % MOD = 1
ll inv[MAX<<2];  // (n * inv[n]) % MOD = 1

void init() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    FOR (i, 2, MAX<<2) {
        fac[i] = fac[i-1]*i % MOD;
        inv[i] = MOD - inv[MOD%i]*(MOD/i) % MOD;
        finv[i] = finv[i-1]*inv[i] % MOD;
    }
}

ll nCk (int n, int k) {
    if (n < k || k < 0 || n < 0) return 0;
    return fac[n]*finv[k]%MOD*finv[n-k]%MOD;
}

ll nHk (int n, int k) {
    return nCk(n-1+k, n-1);
}

int pow_(ll n, ll k) {
    ll res = 1;
    while (k) {
        if (k&1) res = (res * n) % MOD;
        n = n * n % MOD;
        k >>= 1;
    }
    return res;
}

int inv(int n) {
    return pow_(n, MOD-2);
}

int main() {

    init();

    int n, k;
    cin >> n >> k;
    cout << nHk(n, k) << endl;
    return 0;

}
