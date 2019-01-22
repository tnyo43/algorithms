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

    data = vector<ll>(N+1);
  }

  void update(int i, ll x) {
    for (int k = i; k <= N; k += k&-k) data[k] = max(data[k], x);
  }

  ll getMax(int i) {
    ll res = 0;
    for (int k = i; k > 0; k -= k&-k) res = max(res, data[k]);
    return res;
  }
};

int N;

int main() {

  cin >> N;
  BIT bit(N);

  for (int i = 1; i <= N; i++) {
    int x;
    cin >> x;
    bit.update(x, i);
    cout << bit.getMax(x) << endl;
  }
  return 0;
}
