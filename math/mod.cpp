#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define FOR(i,m,n) for (ll i = m; i < n; ++i)

template<int mod> struct ModInt {
    int64_t x;
    ModInt() : x(0) {}
    ModInt(int64_t y) : x(y >= 0 ? y % mod : (y % mod + mod) % mod) {}

    ModInt &operator+=(const ModInt &a) {
        if ((x += a.x) >= mod) x -= mod;
        return *this;
    }

    ModInt &operator-=(const ModInt &a) {
        if ((x += mod - a.x) >= mod) x -= mod;
        return *this;
    }

    ModInt &operator*=(const ModInt &a) {
        x = 1LL * x * a.x % mod;
        return *this;
    }

    ModInt &operator/=(const ModInt &a) {
        *this *= a.inverse();
        return *this;
    }

    ModInt operator-() const {
        return ModInt(-x);
    }

    ModInt operator+(const ModInt a) const {
        return ModInt(*this) += a;
    }

    ModInt operator-(const ModInt a) const {
        return ModInt(*this) -= a;
    }

    ModInt operator*(const ModInt a) const {
        return ModInt(*this) *= a;
    }

    ModInt operator/(const ModInt a) const {
        return ModInt(*this) /= a;
    }

    bool operator==(const ModInt a) const {
        return x == a.x;
    }

    bool operator!=(const ModInt a) const {
        return x != a.x;
    }

    ModInt pow(int64_t k) const {
        ModInt ret(1), mul(x);
        while (k > 0) {
            if (k & 1) ret *= mul;
            mul *= mul;
            k >>= 1;
        }
        return ret;
    }

    ModInt inverse() const {
        return pow(mod - 2);
    }

    friend ostream &operator<<(ostream &os, const ModInt &p) {
        return os << p.x;
    }

    friend istream &operator>>(istream &is, ModInt &a) {
        int64_t t;
        is >> t;
        a = ModInt<mod>(t);
        return (is);
    }
};

// const int MOD = 998244353;
const int MOD = 1e9+7;
using modint = ModInt<MOD>;

#define FOR(i,m,n) for (ll i = m; i < n; ++i)

const int MAX = 1e5+10;

modint fac[MAX<<2];
modint finv[MAX<<2];
modint inv_[MAX<<2];

void init() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv_[1] = 1;
    FOR (i, 2, MAX<<2) {
        fac[i] = fac[i-1]*modint(i);
        inv_[i] = -inv_[MOD%i]*modint(MOD/i);
        finv[i] = finv[i-1]*inv_[i];
    }
}

modint nCk (int n, int k) {
    if (n < k || k < 0 || n < 0) return 0;
    return fac[n]*finv[k]*finv[n-k];
}

modint comb(int n, int k) {
    modint ret(1);
    FOR (i, 1, k+1) ret *= i;
    ret = ret.inverse();
    FOR (i, n-k+1, n+1) ret *= i;
    return ret;
}

modint nHk (int n, int k) {
    return nCk(n-1+k, n-1);
}

int main() {
    init();
}
