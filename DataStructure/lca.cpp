#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;

#define REP(i,n) for (ll i = 0; i < n; ++i)
#define REPR(i,n) for (ll i = n - 1; i >= 0; --i)
#define FOR(i,n,m) for (ll i = n; i < m; ++i)
#define FORE(x,xs) for (auto &x: xs)

const int MAX = 1e5;

struct LCA{
private:
    int V;
    int logV;
    int root;
    vvi G; // 隣接ノード
    vvi  parent; // parent[k][v] : vが親を2^k会辿って到着する頂点

    void dfs(int v, int p, int d){ // v:ノード、 p:vの親、 d:vの深さ。
        parent[0][v] = p;
        depth[v] = d;
        FORE (next, G[v]) {
        if (next != p) dfs(next, v, d+1); 
        } 
    }

public:
    vi depth; // 根からの深さ

    LCA(const vvi &g) {
        G = g;
        V = g.size();
        logV = log2(V)+1;
        parent = vvi(logV, vi(V));
        depth = vi(V);
        root=0;
        dfs(root, -1, 0);

        // parentの初期化
        REP (k, logV-1) {
        REP (v, G.size()) {
            if (parent[k][v] < 0) parent[k+1][v] = -1;
            else parent[k+1][v] = parent[k][parent[k][v]];
        }
        }
    }

    int lca(int u,int v) {
        if (depth[u] > depth[v]) swap(u, v);
        REP (k, logV) {
        if ((depth[v]-depth[u])>>k & 1){
            v = parent[k][v];
        }
        }
        if (u==v) return u;
        REPR (k, logV) {
        if (parent[k][u] != parent[k][v]) {
            u = parent[k][u];
            v = parent[k][v];
        }
        }
        return parent[0][u];
    }

    vvi getG(){
        return G;
    }
};

int main() {
    int N, Q, x, y;
    cin >> N;
    vvi G(N);

    REP (n, N-1) {
        cin >> x >> y;
        x--; y--;
        G[x].push_back(y);
        G[y].push_back(x);
    }

    LCA tree = LCA(G);

    cin >> Q;
    REP (q, Q) {
        cin >> x >> y;
        x--; y--;
        int p = tree.lca(x, y);
        cout << tree.depth[x]+tree.depth[y]-2*tree.depth[p]+1 << endl;
    }

    return 0;
}
