#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
#define REP(i,n) for (ll i = 0; i < n; ++i)
 
template <typename T> struct Matrix {
private:
    typedef vector<T> vt;
    typedef vector<vt> vvt;
 
    void init(vvt A) {
        N = A.size(), M = A[0].size();
        data = vvt(N, vt(M));
        REP (i,N) copy(A[i].begin(), A[i].end(), data[i].begin());
    }
 
public:
    int N, M;
    vvt data;
 
    Matrix (int n, int m) { init(vvt(n, vt(m))); }
    Matrix (vvt A) { init(A); }
 
    Matrix operator~() { // transverse
        Matrix res(M, N);
        for (int j = 0; j < N; ++j) for (int i = 0; i < M; ++i)
            res.data[i][j] = data[j][i];
        return res;
    }
 
    Matrix &operator+= (const Matrix& b) {
        REP (i, N) REP (j, M) data[i][j] += b.data[i][j];
        return *this;
    }
 
    Matrix &operator-= (const Matrix& b) {
        REP (i, N) REP (j, M) data[i][j] -= b.data[i][j];
        return *this;
    }
 
    Matrix &operator*= (const Matrix& b) {
        int L = b.M;
        Matrix ret(N, L);
        REP (i, N) REP (j, L) {
            REP (k, M) ret.data[i][j] += data[i][k] * b.data[k][j];
        }
        M = L;
        data = ret.data;
        return *this;
    }
 
    Matrix &operator*= (const T c) {
        REP (i, N) REP (j, M) data[i][j] *= c;
        return *this;
    }
 
    Matrix operator-() const {
        Matrix ret = Matrix(*this);
        REP (i, N) REP (j, M) ret.data[i][j] = -ret.data[i][j];
        return ret;
    }
 
    Matrix operator+(const Matrix& b) const { return Matrix(*this) += b; }
    Matrix operator-(const Matrix& b) const { return Matrix(*this) -= b; }
    Matrix operator*(const Matrix& b) const { return Matrix(*this) *= b; }
    Matrix operator*(const T c) const { return Matrix(*this) *= c; }
 
    Matrix pow(int64_t k) const {
        Matrix ret(N, N);
        REP (i, N) ret.data[i][i] = T(1);
        Matrix tmp(data);
        while (k) {
            if (k&1) ret *= tmp;
            tmp *= tmp;
            k >>= 1;
        }
        return ret;
    }
 
    friend ostream &operator<<(ostream &os, const Matrix &p) {
        os << "[";
        REP (i, p.N) {
            os << "[";
            REP (j, p.M) os << p.data[i][j] << ((j == p.M-1)?"]":",");
            os << ((i == p.N-1)?"]":",");
        }
        return os;
    }
};