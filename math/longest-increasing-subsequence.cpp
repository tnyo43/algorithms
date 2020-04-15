#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
#define REP(i,n) for (ll i = 0; i < n; ++i)

#define ALL(v) v.begin(), v.end()

class LIS {
private:
    int N;
    vi xs;

    void init(vi& vs) {
        N = vs.size();
        xs = vs;
    }

public:
    LIS() {}
    LIS(vi xs) { init(xs); }

    vi solve(bool isStrict = false) {
        vi dp(N, 1e9), idx(N);
        REP (i, N) {
            if (isStrict) idx[i] = upper_bound(ALL(dp), xs[i]) - dp.begin();
            else idx[i] = lower_bound(ALL(dp), xs[i]) - dp.begin();
            dp[idx[i]] = xs[i];
        }

        int l = *max_element(ALL(idx));
        vi ret(l+1);
        REP (i, N) if (idx[N-1-i] == l) ret[l--] = xs[N-1-i];
        return ret;
    }
};