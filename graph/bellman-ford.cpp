#include <iostream>

using namespace std;

typedef long long ll;

#define REP(i,n) for (ll i = 0; i < n; ++i)

const ll INF = 1e17;
const int NMAX = 1e5; // 最大頂点数
const int MMAX = 1e5; // 最大辺

ll N, M; // N:頂点数、M:辺の数

int a[MMAX], b[MMAX], c[MMAX];
ll dist[NMAX]; // dist[j]は注目する頂点kからの最短距離、特にdist[k]=0


bool bellman_ford(int s) { // 負の閉路があるときtrueを返す
    fill_n(dist, N, INF);
    dist[s] = 0;
    REP (loop, N-1) {
        REP (m, M) {
        if (dist[a[m]] == INF) continue; // まだdist[a[i]]にたどり着いていないので考慮しない
        dist[b[m]] = min(dist[b[m]], dist[a[m]] + c[m]);
        }
    }

    REP (m, M) if (dist[b[m]] > dist[a[m]] + c[m]) return true;
    return false;
}

int main() {
    cin >> N >> M;
    REP (i, M) {
        cin >> a[i] >> b[i] >> c[i];
        a[i]--;
        b[i]--;
    }

    if (bellman_ford(0)) cout << "has loop" << endl;
    cout << dist[N-1] << endl;

    return 0;
}
