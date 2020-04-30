#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define REP(i,n) for (ll i = 0; i < n; ++i)
#define ALL(v) v.begin(), v.end()

template<typename T, bool directed, T inf> class FordFulkerson {
private:
    struct Edge {
        int to; T cap; int rev;
        Edge(int to, T cap, int rev) : to(to), cap(cap), rev(rev) {}
    };

    vector<vector<Edge>> G;
    vector<bool> used;

    void init(int n) {
        G = vector<vector<Edge>>(n);
        used = vector<bool>(n);
    }

    T dfs(int s, int t, T f) {
        if (s == t) return f;

        used[s] = true;
        REP (i, G[s].size()) {
            Edge &e = G[s][i];
            if (!used[e.to] && e.cap > T(0)) {
                T d = dfs(e.to, t, min(f, e.cap));
                if (d == T(0)) continue;
                e.cap -= d;
                G[e.to][e.rev].cap += d;
                return d;
            }
        }

        return T(0);
    }

public:
    FordFulkerson() {}
    FordFulkerson(int n) { init(n); }

    void add(int from, int to, T cap) {
        if (!cap) return;
        G[from].push_back(Edge(to, cap, G[to].size()));
        G[to].push_back(Edge(from, (directed ? 0 : cap), G[from].size()-1));
    }

    T solve(int s, int t) {
        T ret(0);
        while (1) {
            fill(ALL(used), false);
            T f = dfs(s, t, inf);
            if (f == 0) return ret;
            ret += f;
        }
    }
};