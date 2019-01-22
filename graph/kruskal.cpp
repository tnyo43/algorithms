#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

#define REP(i, n) for (ll i = 0; i < (n); ++i)
#define FORE(x, xs) for (auto &x: (xs))
#define ALL(v) v.begin(), v.end()

const int INF = 1000000009;

const int N_MAX = 1e5;
const int M_MAX = 2e5;

int parent[N_MAX];
int rankb[N_MAX];
 
void init(int x) {
    for(int i = 0; i <= x; i++)
    parent[i] = i,rankb[i] = 0;
}
 
int root(int x) {
    return parent[x]==x ? x : parent[x]=root(parent[x]);
}
 
bool same(int x, int y) {
    return root(x) == root(y);
}
 
void unite(int x, int y) {
    x = root(x);
    y = root(y);
    if (x == y) return;

    if (rankb[x] < rankb[y])
        parent[x] = y;
    else {
        parent[y] = x;
        if (rankb[x] == rankb[y]) rankb[x]++;
    }
}

struct Edge {
    int a, b, cost;

    bool operator<(const Edge& o) const {
        return cost < o.cost;
    }
};

ll N, M;
vector<Edge> G;

ll kruskal() { // 求めた最小全域木のコストを返す
    sort(ALL(G));
    init(N);
    ll ans = 0;

    FORE (e, G) {
        if (!same(e.a, e.b)) {
        unite(e.a, e.b);
        ans += e.cost;
        }
    }

    return ans;
}

int main() {
    cin >> N >> M;

    REP (i, M) {
        Edge e;
        cin >> e.a >> e.b >> e.cost;
        e.a--; e.b--;
        G.push_back(e);
    }

    cout << kruskal() << endl;

    return 0;
}
