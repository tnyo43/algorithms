#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;

#define REP(i, n) for (ll i = 0; i < (n); ++i)
#define FOR(i, n, m) for (ll i = (n); i < (m); ++i)
#define FORR(i, n, m) for (ll i = (m)-1; i >= (n); --i)

const int MOD = 1e9+7;

int N;
ll K;

vi succ(vi C) {
  vi CC = vi(k);
  CC[0] = (C[0] + C[k-1])%MOD;
  REP (i, k-1) CC[i+1] = (C[i] + 1l*C[k-1]*C[i+1])%MOD;
  return CC;
}

vi square(vi C) {

}


int kitamasa(vi A, vi C, int n) {
  /*
   * A = {a_0, a_1, ..., a_{k-1}}
   * C = {c_0, c_1, ..., c_{k-1}}
   * に対して
   * 漸化式a_m = SUM i:0->{k-1} a_{m-k+i}*c_i
   * なるa_nを返す
   *
   * 実際はcを更新する
   */
  while (n) {
    if (n&1) C = succ(C);
    C = square(C);
    n >>= 1;
  }

  int res = 0;
  REP (i, K) res = (res + 1l*A[i]*C[i])%MOD;
  return res
}

int main() {

  cin >> K >> N;
  if (N <= K) { // 定義より
    cout << 1 << endl;
    return 0;
  }

  vi A(K, 1); // 初期値、定義より1がK個
  vi C(K, 1); // フィボナッチなのでこちらも1がK個

  cout << kitamasa(A, C, N-K) << endl;

  return 0;
}
