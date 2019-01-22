#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

#define REP(i, n) for (ll i = 0; i < (n); ++i)

const int INF = 1000000009;
const int MAX = 300; // 最大頂点数

ll N, M; // N:頂点数、M:辺の数

int dist[MAX][MAX]; // dist[j][i]=dist[i][j]はi、j間の最短距離

template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    fill( (T*)array, (T*)(array+N), val );
}

void warshall_floyd() {
    REP (k, N) REP (j, N) REP (i, N)
        dist[j][i] = min(dist[j][i], dist[j][k] + dist[k][i]);
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
