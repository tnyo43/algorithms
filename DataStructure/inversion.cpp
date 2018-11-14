#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

struct BIT {
  vector<ll> data;
  int N;

  BIT(int n) {
    N = n;
    data = vector<ll>(N+1);
  }

  void add(int i, ll x) {
    for (int k = i; k <= N; k += k&-k) data[k] += x;
  }

  ll sum(int i) {
    ll res = 0;
    for (int k = i; k > 0; k -= k&-k) res += data[k];
    return res;
  }
};

const int MAX = 1e5+10;

int N, a[MAX];

ll inversion() {

  BIT bit(N);

  ll res = 0;
  for (int i = 0; i < N; i++) {
    res += i-bit.sum(a[i]-1);
    bit.add(a[i], 1);
  }

  return res;
}

int main() {

  cin >> N;
  for (int i = 0; i < N; i++)
    cin >> a[i];

  cout << inversion() << endl;
  return 0;
}
