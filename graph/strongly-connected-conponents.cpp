#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> ii;
typedef vector<ll> vi;
typedef vector<vi> vvi;
#define REP(i,n) for (ll i = 0; i < n; ++i)
#define REPR(i,n) for (ll i = n-1; i >= 0; --i)
#define FOR(i,m,n) for (ll i = m; i < n; ++i)
#define FORE(x,xs) for (const auto& x : xs)
#define ALL(v) v.begin(), v.end()

class StronglyConnectedComponents {
private:
    int N;
    vvi FE, RE; // forward-edges, reversed-edges

    void init(int n) {
        N = n;
        FE.resize(0); FE.clear(); FE.resize(n);
        RE.resize(0); RE.clear(); RE.resize(n);
    }

    void dfs(int v, vector<bool>& visit, vi& order) {
        visit[v] = true;
        FORE (e, FE[v]) {
            if (!visit[e]) dfs(e, visit, order);
        }
        order.push_back(v);
    }

    void rdfs(int v, int k, vector<bool>& visit, vi& comp) {
        visit[v] = true;
        comp[v] = k;
        FORE (e, RE[v]) {
            if (!visit[e]) rdfs(e, k, visit, comp);
        }
    }

public:
    StronglyConnectedComponents() {}
    StronglyConnectedComponents(int n) { init(n); }

    void add(int from, int to) {
        FE[from].push_back(to);
        RE[to].push_back(from);
    }

    pair<vvi, vvi> solve() {
        vi order(0), comp(N);
        vector<bool> visit(N, false);

        REP (i, N) {
            if (!visit[i]) dfs(i, visit, order);
        }

        fill(ALL(visit), false);

        int sccN = 0;
        REPR (i, order.size()) {
            if (!visit[order[i]]) rdfs(order[i], sccN++, visit, comp);
        }

        vvi vertices(sccN);
        REP (i, N) vertices[comp[i]].push_back(i);
        REP (i, sccN) {
            sort(ALL(vertices[i]));
            vertices[i].erase(unique(ALL(vertices[i])), vertices[i].end());
        }

        vvi sccGraph(sccN);
        REP (i, N) REP (j, FE[i].size()) {
            if (comp[i] != comp[FE[i][j]])
                sccGraph[comp[i]].push_back(comp[FE[i][j]]);
        }

        return make_pair(vertices, sccGraph);
    }
};