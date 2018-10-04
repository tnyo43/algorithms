#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

ll GCD(ll x, ll y) {
  if (x > y) swap(x, y);
  while (x) {
    ll z = x;
    x = y%x;
    y = z;
  }
  return y;
}

ll LCM(ll x, ll y) {
  ll g = GCD(x, y);
  return x / g * y;
}

int main() {

  ll x, y;
  cin >> x >> y;
  cout << LCM(x, y) << endl;
  return 0;

}
