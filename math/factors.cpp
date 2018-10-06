#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long ll;
typedef vector<ll> vl;

vector<pair<ll, ll>> factorize(ll N) {
  vector<pair<ll, ll>> res;
  ll n = N;
  for (ll p = 2; p*p <= n; p++) {
    if (N%p != 0) continue;
    int count = 0;
    while (N%p == 0) {
      count++; // pで割れる回数をカウント
      N /= p;
    }
    res.push_back(make_pair(p, count));
  }
  if (N != 1) res.push_back(make_pair(N, 1)); // 最終的にNが素数のとき
  return res;
}

vl getFactors(ll N) {
  vector<pair<ll, ll>> f = factorize(N);
  vl res;
  res.push_back(1);
  for (int i = 0; i < f.size(); i++) {
    int s = res.size();
    for (int j = 0; j < s; j++) for (int k = 0; k < f[i].second; k++) {
      res.push_back(res[j]*pow(f[i].first, k+1));
    }
  }
  sort(res.begin(), res.end());
  return res;
}

int main() {
  ll N;
  cin >> N;
  vl factors = getFactors(N);
  cout << "factors of " << N << ": ";
  for (int i = 0; i < factors.size(); i++) cout << factors[i] << " ";
  cout << endl;
  return 0;
}
