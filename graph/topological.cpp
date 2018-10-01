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

const int MAX = 26;

struct TopologicalSort {
private:
  vvi E;

  bool visit(int v, vi& order, vi& color) {
    color[v] = 1;
    FORE (x, E[v]) {
      if (color[x] == 2) continue;
      if (color[x] == 1) return false;
      if (!visit(x, order, color)) return false;
    }
    order.push_back(v);
    color[v] = 2;
    return true;
  }

public:
  void add_edge(int a, int b) { /// aがbより先にあるa->b
    E[a].push_back(b);
  }

  TopologicalSort (int N) { /// ノードの数で初期化
    E.resize(N);
  }

  bool sort(vi& order) { /// 
    int n = E.size();
    vi color(n);
    REP (i, n) if (!color[i] && !visit(i, order, color)) return false;
    reverse(order.begin(), order.end());
    return true;
  }
};

int N, M;
string A[MAX], B[MAX];
int edge[MAX][MAX];

int main() {

  int a, b;
  TopologicalSort ts(26);

  cin >> N;
  REP (i, N) {
    cin >> A[i];
    REP (j, A[i].length()-1) {
      a = A[i][j] - 'A';
      b = A[i][j+1] - 'A';
      if (!edge[a][b]) ts.add_edge(a, b);
      edge[a][b] = 1;
    }
  }

  cin >> M;
  REP (i, M) {
    cin >> B[i];
    REP (j, B[i].length()-1) {
      a = B[i][j] - 'A';
      b = B[i][j+1] - 'A';
      if (!edge[a][b]) ts.add_edge(a, b);
      edge[a][b] = 1;
    }
  }

  vi ord;
  bool res = ts.sort(ord);
  if (!res) {
    cout << -1 << endl;
    return 0;
  }

  REP (i, MAX) cout << ord[i] << " ";
  cout << endl;

  return 0;

}
