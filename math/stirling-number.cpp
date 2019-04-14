#include <iostream>

using namespace std;
typedef long long ll;

#define FOR(i, n, m) for (ll i = (n); i < (m); ++i)

const int MOD = 1000000007;
const int MAX = 1e5+10;

ll fac[MAX<<2];
ll finv[MAX<<2];
ll inv[MAX<<2];

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

ll pow(ll n, ll k) {
    ll res = 1;
    (n += MOD) %= MOD;
    while (k) {
        if (k&1) res = res * n % MOD;
        k >>= 1;
        n = n*n % MOD;
    }
    return res;
}

ll S(ll n, int k) {
    ll res = 0;
    FOR (i, 1, k+1) {
        res += pow(-1, k-i) * nCk(k, i) % MOD * pow(i, n) % MOD;
        res %= MOD;
    }
    return res;
}

int main () {
    init();
    ll n, k;
    cin >> n >> k;
    cout << S(n, k) << endl;
}