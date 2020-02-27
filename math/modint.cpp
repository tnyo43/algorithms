#include <bits/stdc++.h>
using namespace std;

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

const int MOD = 998244353;
// const int MOD = 1e9+7;

using modint = ModInt<MOD>;

int main() {
    
}