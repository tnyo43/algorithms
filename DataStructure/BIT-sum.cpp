#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

struct BIT {
  vector<ll> data;
  int N;

  BIT(int n) {
    N = 1;
    while (N < n) N *= 2;
    N *= 2;

    data = vector<ll>(N+1);
  }

  void add(int i, ll x) {
    for (int k = i; k <= N; k += k&-k) data[k] += x;
  }

  void update(int i, ll x) {
    add(i, x-get(i));
  }

  ll sum(int i) {
    ll res = 0;
    for (int k = i; k > 0; k -= k&-k) res += data[k];
    return res;
  }

  ll get(int i) {
    return sum(i) - sum(i-1);
  }

};

int N, Q;

int main() {

  cin >> N >> Q;
  BIT bit(N);

  for (int i = 0; i < Q; i++) {
    int c, x, y;
    cin >> c >> x >> y;
    if (c == 0) bit.add(x, y);
    else cout << bit.get(x) << endl;
  }

  return 0;
}
