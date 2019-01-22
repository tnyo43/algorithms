#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;

#define REP(i,n) for (ll i = 0; i < n; ++i)
#define FORE(x,xs) for (auto &x: xs)

const int INF = 1000000009;

const int MAX = 1e5; // 最大頂点数

ll N, M; // N:頂点数、M:辺の数

vii G[MAX]; // G[i]は頂点iから出る辺、<行き先、距離>
int dist[MAX]; // dist[j]は注目する頂点kからの最短距離、特にdist[k]=0

void dijkstra(int s) { // sは始点
    fill_n(dist, N, INF);
    priority_queue<ii> q;
    q.push(make_pair(0, s)); // queueは距離、始点の順で使う。大きい方が優先されるので、距離は負の値で扱う
    while (!q.empty()) {
        int t, d; // t:終点、d:始点からtまでの距離
        tie(d, t) = q.top(); q.pop();
        if (dist[t] != INF) continue;
        dist[t] = -d;
        FORE (e, G[t]) {
        q.push(make_pair(d-e.second, e.first));
        }
    }
}

int main() {
    cin >> N >> M;
    REP (i, M) {
        int a, b, t;
        cin >> a >> b >> t;
        a--; b--;
        G[a].push_back(make_pair(b, t));
        G[b].push_back(make_pair(a, t));
    }

    int ans = INF;
    REP (s, N) {
        dijkstra(s);
        int res = -1;
        REP (t, N) res = max(res, dist[t]);
        ans = min(ans, res);
    }

    cout << ans << endl;

    return 0;
}
