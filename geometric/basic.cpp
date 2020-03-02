#include <bits/stdc++.h>
using namespace std;

typedef long double ld;

const ld EPS = 1e-8;

bool equals (const ld &a, const ld &b) {
    return abs(a - b) < EPS;
}

struct Vec2 {
    ld x, y;
    Vec2(ld x = 0, ld y = 0) : x(x), y(y) {}

    Vec2 &operator+=(const Vec2 &p) {
        x += p.x;
        y += p.y;
        return *this;
    }

    Vec2 &operator-=(const Vec2 &p) {
        x -= p.x;
        y -= p.y;
        return *this;
    }

    Vec2 &operator*=(const ld &a) {
        x *= a;
        y *= a;
        return *this;
    }

    Vec2 operator+(const Vec2 &p) const {
        return Vec2(*this) += p;
    }

    Vec2 operator-(const Vec2 &p) const {
        return Vec2(*this) -= p;
    }

    Vec2 operator*(const ld &a) const {
        return Vec2(*this) *= a;
    }

    ld sqrtNorm() const {
        return x*x + y*y;
    }

    ld norm() const {
        return sqrt(sqrtNorm());
    }

    Vec2 unit() const {
        return Vec2(*this) * (1/norm());
    }

    Vec2 rotate90() const {
        return Vec2(y, -x);
    }

    ld innerProduct(const Vec2 &p) {
        return x*p.x + y*p.y;
    }

    friend ostream &operator<<(ostream &os, const Vec2 &p) {
        return os << "{" << p.x << "," << p.y << "}";
    }
};

struct Circle {
    Vec2 o;
    ld r;
    Circle(Vec2 o = Vec2(), ld r = 0) : o(o), r(r) {}

    vector<Vec2> crossPoints(const Circle &c) {
        Vec2 v = c.o - o;
        ld l = v.norm();

        // 中心が近すぎると交点が存在しない
        if (equals(l, 0)) return vector<Vec2>();

        // 円同士が外接/内接すると交点は一つ
        if (equals((l + r + c.r), 2 * max({l, r, c.r}))) {
            if (equals(c.r, r + l)) return vector<Vec2>({o - v*(r/l)});
            return vector<Vec2>({o + v*(r/l)});
        }

        // 共有部分を持たない/内包しているなら交点が存在しない
        if (l + r + c.r < 2 * max({l, r, c.r})) return vector<Vec2>();

        ld x = (r*r + l*l - c.r*c.r) / (2*l);
        ld y = sqrt(r*r - x*x);
        Vec2 mid = o + v.unit() * x;
        Vec2 e = v.unit().rotate90();
        return vector<Vec2>({mid + e * y, mid - e * y});
    }

    bool isInside(const Vec2 &p) {
        return (p-o).norm() < r + EPS;
    }

    friend ostream &operator<<(ostream &os, const Circle &c) {
        return os << "O: " << c.o << ", r: " << c.r;
    }
};

struct Line {
    Vec2 s, t;
    Line(Vec2 s = Vec2(), Vec2 t = Vec2()) : s(s), t(t) { assert(!equals((s-t).norm(), 0)); }

    vector<Vec2> crossPoint(const Line &l) {
        if (isParallel(l)) return vector<Vec2>();

        // thisがy軸に並行
        if (equals(s.y, t.y)) {
            ld p = (s.y - l.t.y) / (l.s.y - l.t.y);
            return vector<Vec2>({l.s*p + l.t*(1-p)});
        }

        // thisがx軸に並行
        if (equals(s.x, t.x)) {
            ld p = (s.x - l.t.x) / (l.s.x - l.t.x);
            return vector<Vec2>({l.s*p + l.t*(1-p)});
        }

        ld p = ((l.t.y - t.y) / (s.y - t.y) - (l.t.x - t.x) / (s.x - t.x))
                / ((l.s.x - l.t.x) / (s.x - t.x) - (l.s.y - l.t.y) / (s.y - t.y));

        return vector<Vec2>({l.s*p + l.t*(1-p)});
    }

    bool isParallel(const Line &l) {
        Vec2 e1 = (s-t).unit();
        Vec2 e2 = (l.s-l.t).unit();
        return equals((e1 - e2).norm(), 0);
    }

    bool isSame(const Line &l) {
        return isParallel(l) && isParallel(Line(s, l.s));
    }

    // 法線ベクトルの「始点」と「ベクトルの向き」と「大きさ」
    tuple<Vec2, Vec2, ld> normalVector(const Vec2 &p) {
        // pが直線上なら
        if (Line(p,s).isParallel(Line(s,t))) return make_tuple(p, (s-t).rotate90().unit(), 0);
        Vec2 q = (s-t).unit() * ((s-t).unit().innerProduct(p-t)) + t;
        Vec2 n = p - q;
        return make_tuple(q, (s-t).rotate90().unit(), n.norm());
    }

    ld distance(const Vec2 &p) {
        return get<2>(normalVector(p));
    }

    vector<Vec2> crossPoint(const Circle &c) {
        tuple<Vec2, Vec2, ld> n = normalVector(c.o);
        // thisが円の接線なら、接点だけ
        if (equals(get<2>(n), c.r)) {
            return vector<Vec2>({get<0>(n)});
        }

        // 接してないならない
        if (get<2>(n) > c.r) return vector<Vec2>();

        // それ以外は2点ある
        Vec2 l = (s-t).unit() * sqrt(c.r * c.r - get<2>(n) * get<2>(n));
        return vector<Vec2>({get<0>(n) + l, get<0>(n) - l});
    }

    Line perpendicularBisector() const {
        Vec2 o = (s + t) * 0.5;
        Vec2 r = (s - t).rotate90();
        return Line(o, r);
    }

    friend ostream &operator<<(ostream &os, const Line &l) {
        return os << "s: " << l.s << ", t: " << l.t;
    }
};