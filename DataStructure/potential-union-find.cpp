#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

#define REP(i,n) for (ll i = 0; i < n; ++i)

const int MAX = 2e5;

int parent[MAX];
int rankb[MAX];
ll weight[MAX];
 
void init(int x) {
    for(int i = 0; i <= x; i++)
    parent[i] = i, rankb[i]=0, weight[i] = 0;
}
 
int root(int x) {
    if (parent[x]==x) return x;
    int r = root(parent[x]);
    weight[x] += weight[parent[x]];
    return parent[x] = r;
}

bool same(int x, int y) {
    return root(x) == root(y);
}

ll calc_weight(int x) {
    root(x);
    return weight[x];
}

bool merge(int x, int y, ll w = 0) { // すでに同じグループならfalse
    w += calc_weight(x); w -= calc_weight(y);
    x = root(x); y = root(y);
    if (x == y)
        return false;
    if (rankb[x] < rankb[y]) {
        swap(x, y);
        w = -w;
    }
    if (rankb[x] == rankb[y]) rankb[x]++;
    parent[y] = x;
    weight[y] = w;
    return true;
}

ll diff(int x, int y) {
    return calc_weight(x) - calc_weight(y);
}

ll N, M;

int main() {
    cin >> N >> M;

    bool ans = true;

    init(N);
    REP (m, M) {
        int l, r, d;
        cin >> l >> r >> d;
        l--; r--;
        if (same(l, r)) ans &= (diff(r, l) == d);
        else merge(l, r, d);
    }

    cout << (ans?"Yes":"No") << endl;

    return 0;
}
