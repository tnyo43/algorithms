#include <iostream>
#include <vector>
#include <climits>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;

#define REP(i, n) for (int i = 0; i < (n); i++)

const ll MOD = LLONG_MAX; // 1e9+7;

vvl initialize(int r, int c) {
    /*
     * r行c列の2次元零行列
     */
    vvl I = vvl(r);
    REP (i, r) {
        I[i] = vl(c, 0);
    }
    return I;
}

vvl mul(vvl A, vvl B) { // A*B
    vvl C = initialize(A.size(), B[0].size());
    REP (i, A.size()) REP (k, B.size()) REP (j, B[0].size()) {
        C[i][j] = (C[i][j] + 1l * A[i][k] * B[k][j]) %MOD;
    }
    return C;
}

vvl pow(vvl A, ll n) { 
    /*
     * Aのn乗の行列
     * Aは正方行列
     */
    int d = A.size();
    vvl B = initialize(d, d);
    REP (i, d) B[i][i] = 1; // Aと同じ次元の単位行列を作成
    while (n > 0) {
        if (n&1) B = mul(A, B);
        A = mul(A, A);
        n >>= 1;
    }
    return B;
}

ll fibonacci(ll n) {
    vvl A = initialize(2,2);
    A[0][0] = A[0][1] = A[1][0] = 1;
    A[1][1] = 0;
    A = pow(A, n+1);
    return A[1][0];
}

ll n;

int main() {
    cin >> n;
    cout << fibonacci(n) << endl;;
    return 0;
}