#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

#define REP(i,n) for (ll i = 0; i < n; ++i)

const int MAX = 2e5;

int parent[MAX];
int rankb[MAX];
 
void init(int x) {
    for(int i = 0; i <= x; i++)
    parent[i] = i,rankb[i] = 0;
}
 
int root(int x) {
    return (parent[x]==x) ? x : parent[x]=root(parent[x]);
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

ll N, Q;

int main() {
    cin >> N >> Q;

    init(N);
    REP (q, Q) {
        int p, a, b;
        cin >> p >> a >> b;
        if (p == 0) // 合成
            unite(a, b);
        else 
        cout << (same(a, b) ? "Yes" : "No")  << endl;
    }

    return 0;
}
