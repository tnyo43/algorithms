#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

#define REP(i,n) for (int i = 0; i < n; ++i)
#define FORE(x,xs) for (auto &x: xs)

const int MAX = 1e5+10;

int N, M;
int color[MAX];
int white;
vi G[MAX];

bool dfs(int u, int p, int c) {
    /*
     * u：注目しているノード
     * p：注目しているノードに来る前のところ。重複を防ぐため
     * c：注目しているノードの色
     *
     * 戻り値<bool>：二部グラフかどうかを返す
     */
    color[u] = c;
    if (c == 1) white++;
    FORE (v, G[u]) if (v != p) {
        if (color[v] == -1) { // 色がまだ決まってないなら
        if (!dfs(v, u, 1-c)) return false;
        } else if (color[v] != 1-c) { // 隣接するノードの色が同じなら
        return false;
        }
    }
    return true;
}

int BipartiteGraph() {
    /*
     * 戻り値<int>：二部グラフなら一方のグループのノード数。二部グラフでないなら-1
     */

    if (!dfs(0, -1, 0)) return -1;
    REP (i, N) 
        if (color[i] == -1) return -1; // 連結でないノードがあるとき
    return white;
}

int main() {
    cin >> N >> M;
    REP (i, N) color[i] = -1;

    REP (i, M) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    int res = BipartiteGraph();
    if (res == -1) // 二部グラフでないとき
        cout << 1l*N*(N-1)/2 - M << endl;
    else
        cout << 1l*res*(N-res) - M << endl;

    return 0;
}
