#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef vector<ll> vi;
#define REP(i,n) for (ll i = 0; i < n; ++i)
#define FORE(x,xs) for (const auto& x : xs)

struct UnionFind {
private:
    int N;
    vi parent;
    vi rank_;
 
    void init(int n) {
        N = n;
        parent.resize(0); parent.clear(); parent.resize(n);
        REP (i, N) parent[i] = i;
        rank_.resize(0); rank_.clear(); rank_.resize(n);
    }
 
public:
    UnionFind() { init(0); }
    UnionFind(int n) { init(n); }
 
    int root(int x) {
        return (parent[x] == x) ? x : parent[x] = root(parent[x]);
    }
 
    bool isSame(int x, int y) {
        return root(x) == root(y);
    }
 
    void merge(int x, int y) {
        x = root(x);
        y = root(y);
        if (x == y) return;
 
        if (rank_[x] < rank_[y])
            parent[x] = y;
        else {
            parent[y] = x;
            if (rank_[x] == rank_[y]) rank_[x]++;
        }
    }
};

template<typename T> struct Kruskal {
private:
    int N;
    vector<tuple<T, int, int>> G;
 
    void init(int n) {
        N = n;
        G = vector<tuple<T, int, int>>(0);
    }
 
public:
    Kruskal() {}
    Kruskal(int n) { init(n); }
 
    void add(int u, int v, T w) {
        G.push_back(make_tuple(w, u, v));
    }
 
    pair<T, vector<vector<pair<int, T>>>> solve() {
        sort(ALL(G));
        UnionFind uf(N);
        T ret(0);
        vector<vector<pair<int, T>>> graph(N);
        FORE (e, G) {
            int u, v; T w;
            tie (w, u, v) = e;
            if (uf.isSame(u, v)) continue;
            uf.merge(u, v);
            ret += w;
            graph[u].push_back(make_pair(v, w));
            graph[v].push_back(make_pair(u, w));
        }
        return make_pair(ret, graph);
    }
};