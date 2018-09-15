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

const ll INF = 1e18;
const int MOD = 1000000007;
const double EPS = 1e-14;
const double PI = acos(-1);

const int MAX = 1e5;

template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}

struct Edge {
  int to;  /// 辺の行き先
  ll cap; /// 辺の容量 
  int rev; /// G[e.to][e,rev]は逆辺の構造体にアクセスする
};

vector<Edge> G[MAX];
bool used[MAX];

void add_edge(int from, int to, ll cap) { /// from-to間の流量をcapで設定、お互いにアクセス可能にする
  Edge e1, e2;
  e1.to = to; e1.cap = cap; e1.rev = (int)(G[to].size()); 
  e2.to = from; e2.cap = cap; e2.rev = (int)(G[from].size()); 
  G[from].push_back(e1);
  G[to].push_back(e2);
}

ll dfs(int s, int t, ll f) { /// sからtへ行くルートの最大流量、これ以上ルートがないとき0
  if (s == t) return f;

  used[s] = true;
  REP (i, G[s].size()) {
    Edge& e = G[s][i];
    if (!used[e.to] && e.cap > 0) {
      int d = dfs(e.to, t, min(f, e.cap));
      if (d > 0) {
        e.cap -= d;
        G[e.to][e.rev].cap += d;
        return d;
      }
    }
  }

  return 0;
}

ll ford_fulkerson(int s, int t) { /// sからtへの最大流量を返す
  ll flow = 0;
  while (1) {
    Fill(used, false);
    int f = dfs(s, t, INF);
    if (f == 0) return flow;
    flow += f;
  }
}

int N, M;

int main() {

  cin >> N >> M;

  REP (i, M) {
    int a, b;
    cin >> a >> b;
    add_edge(a, b, 1);
  }

  ll ans = ford_fulkerson(0, N-1);
  cout << ans << endl;

  return 0;

}
