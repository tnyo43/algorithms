#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define REP(i,n) for (ll i = 0; i < n; ++i)
#define FORE(x,xs) for (const auto& x : xs)

class BipartiteMatching {
private:
    vector<vector<int>> G;
    vector<int> match, used;
    vector<bool> isAlive;
    int timestamp;

    void init(int n) {
        G = vector<vector<int>>(n);
        match = vector<int>(n, -1);
        isAlive = vector<bool>(n, true);
        used = vector<int>(n, 0);
        timestamp = 0;
    }

    bool dfs(int u) {
        used[u] = timestamp;
        FORE (v, G[u]) if (isAlive[v]) {
            int to_match = match[v];
            if (to_match == -1 || used[to_match] != timestamp && dfs(to_match)) {
                match[u] = v;
                match[v] = u;
                return true;
            }
        }
        return false;
    }

public:
    BipartiteMatching() {}
    BipartiteMatching(int n) { init(n); }

    void add(int u, int v) {
        G[u].push_back(v);
        G[v].push_back(u);
    }

    vector<pair<int, int>> solve() {
        REP (i, G.size()) if (isAlive[i]) {
            if (match[i] == -1) {
                timestamp++;
                dfs(i);
            }
        }
        vector<pair<int,int>> ret;
        REP (i, G.size()) if (i < match[i]) {
            ret.push_back(make_pair(i, match[i]));
        }
        return ret;
    }
};