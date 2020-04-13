#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> ii;
typedef vector<ll> vi;
typedef vector<ii> vii;
typedef vector<vii> vvii;
#define REP(i,n) for (ll i = 0; i < n; ++i)
#define FORE(x,xs) for (const auto& x : xs)


const ll INF = 1ll<<61;

template<typename T> using min_priority_queue = priority_queue<T, vector<T>, greater<T>>;

class Dijkstra {
private:
    int N;
    vvii E;

    void init(int n) {
        E.resize(0); E.clear();
        N = n; E.resize(n);
    }

public:
    Dijkstra() {}
    Dijkstra(int n) { init(n); }

    void add(int from, int to, int cost) {
        E[from].push_back(ii(to, cost));
    }


    vi solve(int s) {
        vi dis(N, INF);
        vector<bool> vis(N);
        dis[s] = 0;

        min_priority_queue<ii> q;
        q.push(ii(0, s));

        while (!q.empty()) {
            int t, d;
            tie(d, t) = q.top(); q.pop();

            if (vis[t]) continue;
            vis[t] = true;

            FORE (p, E[t]) {
                ll next = p.first, c = p.second;
                if (vis[next]) continue;
                if (dis[t] + c < dis[next]) {
                    dis[next] = dis[t] + c;
                    q.push(ii(dis[next], next));
                } else if (dis[t] + c == dis[next]) {
                }
            }
        }
        return dis;
    }

    pair<vi, vector<modint>> solve_(int s) {
        vi dis(N, INF);
        vector<modint> pat(N, modint(0));
        vector<bool> vis(N);
        dis[s] = 0;
        pat[s] = modint(1);

        min_priority_queue<ii> q;
        q.push(ii(0, s));

        while (!q.empty()) {
            int t, d;
            tie(d, t) = q.top(); q.pop();

            if (vis[t]) continue;
            vis[t] = true;

            FORE (p, E[t]) {
                ll next = p.first, c = p.second;
                if (vis[next]) continue;
                if (dis[t] + c < dis[next]) {
                    dis[next] = dis[t] + c;
                    pat[next] = pat[t];
                    q.push(ii(dis[next], next));
                } else if (dis[t] + c == dis[next]) {
                    pat[next] += pat[t];
                }
            }
        }
        return make_pair(dis, pat);
    }
};