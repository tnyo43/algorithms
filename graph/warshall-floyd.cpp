#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <math.h>
#include <tuple>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

#define REP(i, n) for (ll i = 0; i < (n); ++i)
#define REPR(i, n) for (ll i = (n) - 1; i >= 0; --i)
#define FOR(i, n, m) for (ll i = (n); i < (m); ++i)
#define FORR(i, n, m) for (ll i = (m) - 1; i >= (n); --i) 
#define FORE(x, xs) for (auto &x: (xs))
#define ALL(v) v.begin(), v.end()
#define ZERO(a) memset(a,0,sizeof(a))
#define P(x, y) make_pair(x, y)

const int INF = 1000000009;
const int MOD = 1000000007;
const double EPS = 1e-14;
const double PI = acos(-1);


const int MAX = 300; /// 最大頂点数

ll N, M; /// N:頂点数、M:辺の数

int dist[MAX][MAX]; /// dist[j][i]=dist[i][j]はi、j間の最短距離

template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}

void warshall_floyd() {
  REP (k, N) REP (j, N) REP (i, N) dist[j][i] = min(dist[j][i], dist[j][k] + dist[k][i]);
}

int main() {
  cin >> N >> M;
  Fill(dist, INF);

  REP (i, N) dist[i][i] = 0;
  REP (i, M) {
    int a, b, t;
    cin >> a >> b >> t;
    a--; b--;
    dist[a][b] = dist[b][a] = t;
  }

  warshall_floyd();

  int ans = INF;
  REP (j, N) {
    int res = -1;
    REP (i, N) res = max(res, dist[j][i]);
    ans = min(ans, res);
  }
  cout << ans << endl;

  return 0;
}
