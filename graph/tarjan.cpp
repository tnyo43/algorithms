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

int N, M;
vi G[MAX]; /// グラフの隣接リスト
vi rG[MAX]; /// グラフの隣接リストの逆
vi vs; /// 帰りがけじゅんの並び
bool used[MAX];
int cmp[MAX]; /// 属する強連結成分のトポロジカル順

void add_edge(int from, int to) {
  G[from].push_back(to);
  rG[to].push_back(from);
}

void dfs(int v) { /// 順方向でいけるところを深さ優先探索で探し、vsに追加する
  used[v] = true;
  FORE (x, G[v]) {
    if (!used[x]) dfs(x);
  }
  vs.push_back(v);
}

void rdfs(int v, int k) { /// 逆順で辿れるところを同じkでナンバリングする
  used[v] = true;
  cmp[v] = k;
  FORE (x, rG[v]) {
    if (!used[x]) rdfs(x, k);
  }
}

int scc() {
  fill_n(used, N, false);
  vs.clear();
  REP (v, N)
    if (!used[v]) dfs(v);

  fill_n(used, N, false);
  int k = 0;
  REPR (i, N)
    if (!used[vs[i]]) rdfs(vs[i], k++);
  return k; /// 強連結のグループの数を返す
}

int main() {

  cin >> N >> M;
  REP (m, M) {
    int a, b;
    cin >> a >> b;
    a--; b--;
    add_edge(a, b);
  }

  cout << scc() << endl;

  REP (i, N) cout << vs[i] << " ";
  cout << endl;
  REP (i, N) cout << cmp[i] << " ";
  cout << endl;
  return 0;

}
