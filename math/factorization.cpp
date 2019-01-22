#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<ll> vl;

vector<pair<ll, ll>> factorize(ll N) {
    vector<pair<ll, ll>> res;
    ll n = N;
    for (ll p = 2; p*p <= n; p++) {
        if (N%p != 0) continue;
        int count = 0;
        while (N%p == 0) {
        count++; // pで割れる回数をカウント
        N /= p;
        }
        res.push_back(make_pair(p, count));
    }
    if (N != 1) res.push_back(make_pair(N, 1)); // 最終的にNが素数のとき
    return res;
}

int main() {
    ll N;
    cin >> N;
    vector<pair<ll, ll>> res = factorize(N);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i].first << ":" << res[i].second << endl;
    }
    return 0;
}
