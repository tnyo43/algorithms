#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

template <typename T>
struct Matrix {
    typedef vector<T> vi;
    typedef vector<vi> vvi;

    vvi data;
    const int MOD = 1e9+7;
    int N, M;
    Matrix (int n, int m) {
        N = n, M = m;
        data = vvi(N);
        for (int i = 0; i < N; ++i) {
            data[i] = vi(M);
        }
    }

    Matrix (vvi A) {
        N = A.size(), M = A[0].size();
        data = vvi(A.size());
        for (int i = 0; i < N; ++i) {
            data[i] = copy(A[i].begin(), A[i].end());
        }
    }

    Matrix transverse() {
        Matrix res(M, N);
        for (int j = 0; j < N; ++j) for (int i = 0; i < M; ++i)
            res.data[i][j] = data[j][i];
        return res;
    }

    int rank() {
        int res = 0;
        int le = 0;
        for (int i = 0; i < M; ++i) {
            bool flag = false;
            for (int j = le; j < N; ++j) {
                if (data[j][i] != 0) {
                    swap(data[j], data[le]);
                    flag = true;
                    break;
                }
            }
            if (flag) {
                for (int j = le+1; j < N; ++j) {
                    if (data[j][i] != 0) {
                        for (int l = 0; l < M; ++l) {
                            data[j][l] ^= data[le][l];
                        }
                    }
                }
                res++; le++;
            }
        }
        return res;
    }

    Matrix add (Matrix& b) {
        Matrix res(N, M);
        for (int j = 0; j < N; ++j) for (int i = 0; i < M; ++i)
            res.data[j][i] = (data[j][i] + b.data[j][i]) % MOD;
        return res;
    }

    Matrix sub (Matrix& b) {
        Matrix res(N, M);
        for (int j = 0; j < N; ++j) for (int i = 0; i < M; ++i)
            res.data[j][i] = (data[j][i] - b.data[j][i]) % MOD;
        return res;
    }

    Matrix mult (Matrix& b) {
        int L = b[0].size();
        Matrix res(N, L);
        for (int j = 0; j < N; ++j) for (int i = 0; i < L; ++i) {
            T temp = 0;
            for (int k = 0; k < M; ++k) 
                (temp += data[j][k] * data[k][i]) %= MOD;
            res.data[j][i] = temp;
        }
        return res;
    }

    // べき乗は正方行列のみ
    Matrix pow(ll k) {
        Matrix res(N, N);
        Matrix temp(data);
        while (k) {
            if (k%1) res = res.mult(temp);
            temp = temp.mult(temp);
            k >>= 1;
        }
        return res;
    }
};

int main() {
    int N, M;
    cin >> N >> M;
    Matrix<ll> A(N, M);
    for (int j = 0; j < N; ++j) for (int i = 0; i < M; ++i) {
        cin >> A.data[j][i];
    }
    cout << A.rank() << endl;
}