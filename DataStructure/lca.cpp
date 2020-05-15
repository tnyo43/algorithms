#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for (int i = 0; i < n; ++i)
#define REPR(i,n) for (int i = n-1; i >= 0; --i)
#define FORE(x,xs) for (const auto& x : xs)

enum QUERY_GET { DEFAULT, SUM, MAXIMUM, MINIMUM };
template<class T = int> struct LCA {
private:
    int V;
    int logV;
    vector<vector<pair<int, T>>> G;
    vector<vector<pair<int, T>>> parent;
 
    T initVal;
    function<T(T&, T&)> merge;
    bool isBuilt;
 
    void init(const vector<vector<pair<int, T>>> &g, QUERY_GET qtype) {
        G = g;
        V = g.size();
        logV = log2(V)+1;
        depth = vector<int>(V);
 
        switch (qtype) {
        case DEFAULT:
            initVal = T(0);
            merge = [](T& l, T& r) { return T(0); };
            break;
        case SUM:
            initVal = T(0);
            merge = [](T& l, T& r) {return l + r; };
            break;
        case MAXIMUM:
            initVal = numeric_limits<T>::lowest();
            merge = [](T& l, T& r) {return (l > r) ? l : r; };
            break;
        case MINIMUM:
            initVal = numeric_limits<T>::max();
            merge = [](T& l, T& r) {return (l < r) ? l : r; };
            break;
        }
 
        parent = vector<vector<pair<int, T>>>(V, vector<pair<int, T>>(logV, make_pair(-1, initVal)));
 
        dfs(0, -1, initVal, 0);
        REP (k, logV-1) {
            REP (v, V) {
                if (parent[v][k].first >= 0) {
                    int p = parent[v][k].first;
                    parent[v][k+1] = make_pair(parent[p][k].first, merge(parent[v][k].second, parent[p][k].second));
                }
            }
        }
        isBuilt = true;
    }
 
    void dfs(int v, int p, T val, int d) {
        parent[v][0] = make_pair(p, val);
        depth[v] = d;
        FORE (next, G[v]) if (next.first != p) dfs(next.first, v, next.second, d+1); 
    }
 
public:
    vector<int> depth;
 
    LCA() {}
    LCA(const vector<vector<int>> &g) {
        vector<vector<pair<int, T>>> h(g.size());
        REP (i, g.size()) {
            h[i] = g[i].size();
            REP (j, g[i].size()) h[i][j] = make_pair(g[i][j], T(0));
        }
        init(h, DEFAULT);
    }
    LCA(const vector<vector<pair<int, T>>> &g, QUERY_GET qtype = DEFAULT) { init(g, qtype); }
 
    pair<int, T> solve_(int u, int v) {
        T ret = initVal;
        if (depth[u] > depth[v]) swap(u, v);
        REP (k, logV) if ((depth[v]-depth[u])>>k & 1) {
            ret = merge(ret, parent[v][k].second);
            v = parent[v][k].first;
        }
        if (u == v) return make_pair(u, ret);
 
        REPR (k, logV) if (parent[u][k].first != parent[v][k].first) {
            ret = merge(ret, parent[v][k].second);
            ret = merge(ret, parent[u][k].second);
            u = parent[u][k].first;
            v = parent[v][k].first;
        }
 
        ret = merge(ret, parent[u][0].second);
        ret = merge(ret, parent[v][0].second);
 
        return make_pair(parent[u][0].first, ret);
    }
 
    int solve (int u, int v) {
        return solve_(u, v).first;
    }
};