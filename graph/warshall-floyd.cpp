#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> ii;
typedef vector<ll> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
#define REP(i,n) for (ll i = 0; i < n; ++i)
#define FORE(x,xs) for (const auto& x : xs)

const ll INF = 1ll<<61;

class WarchallFloyd {
private:
    int N;
    vvii E;

    void init(int n) {
        N = n;
        E = vvii(n);
    }

public:
    WarchallFloyd() {}
    WarchallFloyd(int n) { init(n); }

    void add(int from, int to, ll dist) {
        E[from].push_back(make_pair(to, dist));
    }

    vvi solve() {
        vvi ret(N, vi(N, INF));
        REP (i, N) FORE (e, E[i]) {
            ret[i][e.first] = e.second;
        }

        REP (k, N) REP (j, N) REP (i, N) {
            ret[j][i] = min(ret[j][i], ret[j][k] + ret[k][i]);
        }
        return ret;
    }
};