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

const int MAX = 2e5;

int parent[MAX];
int rankb[MAX];
 
void init(int x) {
  for(int i = 0; i <= x; i++)
  parent[i] = i,rankb[i] = 0;
}
 
int root(int x) {
  return parent[x]==x?x:parent[x]=root(parent[x]);
}
 
bool same(int x, int y) {
  return root(x) == root(y);
}
 
void unite(int x, int y) {
  x = root(x);
  y = root(y);
  if (x == y) return;

  if (rankb[x] < rankb[y])
    parent[x] = y;
  else {
    parent[y] = x;
    if (rankb[x] == rankb[y]) rankb[x]++;
  }
}

ll N, Q;

int main() {
  cin >> N >> Q;

  init(N);
  REP (q, Q) {
    int p, a, b;
    cin >> p >> a >> b;
    if (p == 0) // 合成
      unite(a, b);
    else 
      cout << (same(a, b) ? "Yes" : "No")  << endl;
  }

  return 0;
}
