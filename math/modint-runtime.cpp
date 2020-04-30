#include <bits/stdc++.h>
using namespace std;

vector<int> MODS = { 11 };
template<int IND = 0> struct RuntimeModInt {
    int64_t x;
    int mod = MODS[IND];
 
    RuntimeModInt() : x(0) {}
    RuntimeModInt(int64_t y) : x(y % MODS[IND]) { if (y < 0) y += MODS[IND]; }
 
    RuntimeModInt &operator+=(const RuntimeModInt &a) {
        if ((x += a.x) >= mod) x -= mod;
        return *this;
    }
 
    RuntimeModInt &operator-=(const RuntimeModInt &a) {
        if ((x += mod - a.x) >= mod) x -= mod;
        return *this;
    }
 
    RuntimeModInt &operator*=(const RuntimeModInt &a) {
        x = 1LL * x * a.x % mod;
        return *this;
    }
 
    RuntimeModInt &operator/=(const RuntimeModInt &a) {
        *this *= a.inverse();
        return *this;
    }
 
    RuntimeModInt operator-() const {
        return RuntimeModInt(-x);
    }
 
    RuntimeModInt operator+(const RuntimeModInt a) const {
        return RuntimeModInt(*this) += a;
    }
 
    RuntimeModInt operator-(const RuntimeModInt a) const {
        return RuntimeModInt(*this) -= a;
    }
 
    RuntimeModInt operator*(const RuntimeModInt a) const {
        return RuntimeModInt(*this) *= a;
    }
 
    RuntimeModInt operator/(const RuntimeModInt a) const {
        return RuntimeModInt(*this) /= a;
    }
 
    bool operator==(const RuntimeModInt a) const {
        return x == a.x;
    }
 
    bool operator!=(const RuntimeModInt a) const {
        return x != a.x;
    }
 
    RuntimeModInt pow(int64_t k) const {
        RuntimeModInt ret(1), mul(x);
        while (k > 0) {
            if (k & 1) ret *= mul;
            mul *= mul;
            k >>= 1;
        }
        return ret;
    }
 
    RuntimeModInt inverse() const {
        return pow(mod - 2);
    }
 
    friend ostream &operator<<(ostream &os, const RuntimeModInt &p) {
        return os << p.x;
    }
 
    friend istream &operator>>(istream &is, RuntimeModInt &a) {
        int64_t t;
        is >> t;
        a = RuntimeModInt<>(t);
        return (is);
    }
};

int main() {
    MODS[0] = 13;
    using modint = RuntimeModInt<>;
}