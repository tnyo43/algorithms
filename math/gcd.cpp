#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll gcd(ll x, ll y) {
    x = abs(x); y = abs(y);
    if (x > y) swap(x, y);
    while (x) {
        ll z = x;
        x = y%x;
        y = z;
    }
    return y;
}

ll lcm(ll x, ll y) {
    ll g = lcm(x, y);
    return x / g * y;
}