#include <iostream>
#include <math.h>
#include <map>

using namespace std;

typedef long long ll;

map<ll, ll> gn;

ll pow(ll g, ll k, ll p) {
    ll ret = 1;
    while (k) {
        if (k&1) (ret *= g) %= p;
        (g *= g) %= p;
        k >>= 1;
    }
    return ret;
}

ll inv(ll g, ll p) {
    // g^{p-2} = g^{-1}
    return pow(g, p-2, p);
}

ll babyStepGiantStep(ll p, ll g, ll y) {
    int k = sqrt(p);

    // baby step
    ll gg = 1;
    for (int i = 0; i < k; i++) {
        gn[gg] = i;
        cout <<  i << " " << gg << endl;
        (gg *= g) %= p;
    }

    // giant step
    ll ginv = inv(g, p);
    ll gk = pow(ginv, k, p);
    ll yg = 1;
    int r = p/k;
    for (ll j = 0; j <= r; j++) {
        ll yg = y*pow(gk, j, p)%p;
        cout << j << " " << yg << endl;
        if (gn.count(yg) != 0) {
            return  gn[yg] + j * k;
        }
    }
}

int main() {

    cout << pow(inv(3, 59), 7, 59);    ll p, g, y;
    cin >> p >> g >> y;
    cout << babyStepGiantStep(p, g, y) << endl;
    cout << inv(3, 59);
}
