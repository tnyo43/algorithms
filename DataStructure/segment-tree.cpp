#include <bits/stdc++.h>
using namespace std;

template <class T> class SegmentTree {
private:
    int SIZE;
    T zero;
    vector<T> node;
    function<T(T&, T&)> merge;

    void init(int n) {
        SIZE = 1;
        while (SIZE < n) SIZE <<= 1;
        node.resize(SIZE << 1, zero);
    }

public:
    SegmentTree() {}
    SegmentTree(int n, T zero, function<T(T&, T&)> merge) : zero(zero), merge(merge) {
        init(n);
    }

    void update(int i, T val) {
        i += SIZE;
        node[i] = val;
        while (i > 1) {
            i >>= 1;
            node[i] = merge(node[i << 1], node[(i << 1) + 1]);
        }
    }

    void add(int i, T val) { update(i, node[i + SIZE] + val); }

    T query(int l, int r) {
        if (l >= r) return zero;
        T vl = zero, vr = zero;
        for (l += SIZE, r += SIZE; l != r; l >>= 1, r >>= 1) {
            if (l & 1) vl = merge(vl, node[l++]);
            if (r & 1) vr = merge(node[--r], vr);
        }
        return merge(vl, vr);
    }

    T operator[](int i) { return query(i, i+1); }

    SegmentTree<T> maxTree(int n) const {
        SegmentTree<T> ret(
            n,
            numeric_limits<T>::lowest(),
            [](T& l, T& r) { return max(l,r); });
        return ret;
    }

    SegmentTree<T> minTree(int n) const {
        SegmentTree<T> ret(
            n,
            numeric_limits<T>::max(),
            [](T& l, T& r) { return min(l,r); });
        return ret;
    }

    SegmentTree<T> sumTree(int n) const {
        SegmentTree<T> ret(
            n,
            T(0),
            [](T& l, T& r) { return l + r; });
        return ret;
    }
};

#define MaxTree(t, n) SegmentTree<t>().maxTree(n);
#define MinTree(t, n) SegmentTree<t>().minTree(n);
#define SumTree(t, n) SegmentTree<t>().sumTree(n);