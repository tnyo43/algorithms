#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define FOR(i,m,n) for (ll i = m; i < n; ++i)

template <typename ModInt> class ModCalc {
private:
    vector<ModInt> fact, finv, inv_;

    void init(int n) {
        int mx = n*2+10;
        fact = vector<ModInt>(mx);
        finv = vector<ModInt>(mx);
        inv_ = vector<ModInt>(mx);

        fact[0] = fact[1] = ModInt(1);
        finv[0] = finv[1] = ModInt(1);
        inv_[1] = ModInt(1);
        FOR (i, 2, mx) {
            fact[i] = fact[i-1]*ModInt(i);
            inv_[i] = ModInt(i).inverse();
            finv[i] = finv[i-1]*inv_[i];
        }
    }

public:
    ModCalc() {}
    ModCalc(int n) { init(n); }

    ModInt nCk (int n, int k) {
        if (n < k || k < 0 || n < 0) return 0;
        return fact[n]*finv[k]*finv[n-k];
    }

    ModInt nHk (int n, int k) {
        return nCk(n-1+k, n-1);
    }

    ModInt nPk (int n, int k) {
        if (n < k || k < 0 || n < 0) return 0;
        return fact[n]*finv[n-k];
    }

    ModInt factorial(int n) {
        return fact[n];
    }

    ModInt stirling(ll n, int k) {
        ll ret = 0;
        FOR (i, 1, k+1)
            ret += ModInt(-1).pow(k-i) * nCk(k, i) * ModInt(i, n);
        return ret;
    }
};