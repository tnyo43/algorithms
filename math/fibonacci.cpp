#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;

#define REP(i, n) for (int i = 0; i < (n); i++)

const int MOD = 1e9+7;

vvi initialize(int r, int c) {
  /*
   * r行c列の2次元零行列
   */
  vvi I = vvi(r);
  REP (i, r) {
    I[i] = vi(c, 0);
  }
  return I;
}

vvi mul(vvi A, vvi B) { // A*B
  vvi C = initialize(A.size(), B[0].size());
  REP (i, A.size()) REP (k, B.size()) REP (j, B[0].size()) {
    C[i][j] = (C[i][j] + 1l * A[i][k] * B[k][j])%MOD;
  }
  return C;
}

vvi pow(vvi A, ll n) { 
  /*
   * Aのn乗の行列
   * Aは正方行列
   */
  int d = A.size();
  vvi B = initialize(d, d);
  REP (i, d) B[i][i] = 1; // Aと同じ次元の単位行列を作成
  while (n > 0) {
    if (n&1) B = mul(A, B);
    A = mul(A, A);
    n >>= 1;
  }
  return B;
}

int fibonacci(ll n) {
  vvi A = initialize(2,2);
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
