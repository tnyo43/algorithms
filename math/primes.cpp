#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <math.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef pair<ll, ll> P;
typedef vector<int> vi;
typedef vector<vi> vvi;

#define REP(i, n) for (ll i = 0; i < (n); ++i)
#define REPR(i, n) for (ll i = (n) - 1; i >= 0; --i)
#define FOR(i, n, m) for (ll i = (n); i < (m); ++i)
#define FORR(i, n, m) for (ll i = (m) - 1; i >= (n); --i) 
#define FORE(x, xs) for (auto &x: (xs))
#define ALL(v) v.begin(), v.end()
#define ZERO(a) memset(a,0,sizeof(a))

const int INF = 1000000009;
const int MOD = 1000000007;
const double EPS = 1e-14;
const double PI = acos(-1);

const int MAX = 1e5;

vi primes(int n) {
  vector<bool> is_prime(n+1, true);
  is_prime[0] = is_prime[1] = false;

  FOR (i, 2, (int)(pow(n, 0.5)+1)) {
    if (!is_prime[i]) continue;
    int j = i;
    while (j <= n) is_prime[j+=i] = false;
  }

  vi res;
  FOR (i, 2, n+1)
    if (is_prime[i]) res.push_back(i);
  return res;
}

int main() {

  vi p = primes(97);
  FORE (x, p) cout << x << " ";
  cout << endl;
  return 0;

}
