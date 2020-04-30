#include <bits/stdc++.h>
using namespace std;
 
template<typename T, bool directed, T inf> class Dinic {
private:
    struct Edge {
        int to; T cap; int rev;
        Edge(int to, T cap, int rev) : to(to), cap(cap), rev(rev) {}
    };
 
    vector<int> level, iter;
 
    void init(int n) {
        G = vector<vector<Edge>>(n);
        level = vector<int>(n);
        iter = vector<int>(n);
    }
 
    void bfs(int s) {
        fill(ALL(level), -1);
        level[s] = 0;
        queue<int> que;
        que.push(s);
        while (!que.empty()) {
            int n = que.front(); que.pop();
            for (auto &&e : G[n]) if (e.cap > T(0) && level[e.to] < 0) {
                level[e.to] = level[n] + 1;
                que.push(e.to);
            }
        }
    }
 
    T dfs(int s, int t, T f) {
        if (s == t) return f;
        for (int &i = iter[s]; i < G[s].size(); i++) {
            Edge& e = G[s][i];
            if (e.cap > T(0) && level[s] < level[e.to]) {
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
    Dinic() {}
    Dinic(int n) { init(n); }
 
    vector<vector<Edge>> G;
    void add(int from, int to, T cap) {
        if (!cap) return;
        G[from].push_back(Edge(to, cap, G[to].size()));
        G[to].push_back(Edge(from, (directed ? 0 : cap), G[from].size()-1));
    }
 
    T solve(int s, int t, T lim = inf) {
        T ret(0);
        while (1) {
            bfs(s);
            if (level[t] < 0 || lim == 0) return ret;
            fill(ALL(iter), 0);
            while (1) {
                T f = dfs(s, t, lim);
                if (f == T(0)) break;
                ret += f;
                lim -= f;
            }
        }
    }
};