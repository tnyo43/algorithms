#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef vector<ll> vi;
#define REP(i,n) for (ll i = 0; i < n; ++i)
 
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
 
class BipartiteGraph {
private:
    int N;
    UnionFind uf;
    bool valid;
 
    void init(int n) {
        N = n;
        uf = UnionFind(2*N);
        valid = true;
    }
 
public:
    BipartiteGraph() { init(0); }
    BipartiteGraph(int n) { init(n); }
 
    void add(int u, int v) {
        uf.merge(u, v+N);
        uf.merge(u+N, v);
 
        valid &= !(uf.isSame(u, u+N) || uf.isSame(v, v+N));
    }
 
    bool isValid() {
        return valid;
    }
 
    pair<set<int>, set<int>> get() {
        assert(valid);
 
        set<int> u, v;
        REP (i, N) {
            if (uf.isSame(i, 0)) u.insert(i);
            else v.insert(i);
        }
        return make_pair(u, v);
    }
};
 