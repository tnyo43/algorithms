#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> ii;
typedef vector<ll> vi;
typedef vector<ii> vii;
typedef vector<vii> vvii;
#define REP(i,n) for (ll i = 0; i < n; ++i)
#define FORE(x,xs) for (const auto& x : xs)
#define CHMIN(x,y) x = min(x, y)

const ll INF = 1ll<<61;

struct BellmanFord {
private:
    int N;
    vvii E;

    void init(int n) {
        E.resize(0); E.clear();
        N = n; E.resize(n);
    }

public:
    BellmanFord() {}
    BellmanFord(int n) { init(n); }

    void add(int from, int to, int cost) {
        E[from].push_back(ii(to, cost));
    }

    vi solve(int s) {
        vi ret(N, INF);
        ret[s] = 0;
        REP (rep, N-1) {
            REP (n, N) if (ret[n] < INF) FORE (e, E[n]) {
                CHMIN(ret[e.first], ret[n] + e.second);
            }
        }

        vector<bool> isInf(N);
        REP (rep, N) {
            REP (n, N) if (ret[n] < INF) FORE (e, E[n]) {
                if (isInf[n] || ret[e.first] > ret[n] + e.second) {
                    isInf[e.first] = true;
                }
            }
        }

        REP (i, N) if (isInf[i]) ret[i] = -INF;

        return ret;
    }
};

ll N;
vii edges[1000];

ll main() {
    BellmanFord bf(N);
    REP (i, N) FORE (e, edges[i]) {
        bf.add(i, e.first, e.second);
    }

    int s = 0;
    vi res = bf.solve(s);
    cout << "distance from " << s << "\n";
    REP (i, N) {
        cout << i << ", ";;
        if (res[i] == -INF) cout << "-INF";
        else cout << res[i];
        cout << endl;
    }
}