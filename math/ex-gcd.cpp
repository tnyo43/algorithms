#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

ll extGCD(ll a, ll b, ll &x, ll &y) {
    /*
     * ax + by = GCD(a, b) を計算
     * 戻り値はGCD(a, b)で、x, yはそれぞれ格納される
     */
    if (b==0) { // 最大公約数はa
        x = 1;
        y = 0;
        return a;
    } else {
        ll g = extGCD(b, a%b, y, x); 
        y -= a/b * x;
        return g; // gは共通
    }
}

int main() {
  ll a, b, x, y;
  cin >> a >> b;
  extGCD(a, b, x, y);
  cout << x << " " << y << endl;
  return 0;
}
