#include <iostream>
#include <math.h>

using namespace std;

typedef long long ll;

#define FOR(i, n, m) for (ll i = (n); i < (m); ++i)

const int MOD = 1000000007;

const int MAX = 2e5+1;

ll fac[MAX];  /// fac[n] = n!
ll finv[MAX]; /// (fac[n] * finv[n]) % MOD = 1
ll inv[MAX];  /// (n * inv[n]) % MOD = 1

void init() {
  fac[0] = fac[1] = 1;
  finv[0] = finv[1] = 1;
  inv[1] = 1;
  FOR (i, 2, MAX) {
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

int main() {

  init();

  int n, k;
  cin >> n >> k;
  cout << nHk(n, k) << endl;
  return 0;

}
