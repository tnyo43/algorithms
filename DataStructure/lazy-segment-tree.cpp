#include <bits/stdc++.h>
using namespace std;

template<class T> class LazySegmentTree {
private:
    int SIZE;
    vector<T> node, lazy;
    T nodeZero, lazyZero;
    function<T(T&, T&)> nodeMerge, lazyMerge, nodeMergeWithLazy;
    const function<T(T&, T&)> add_function = [](T& l, T& r) { return l+r; };

    void eval(int k) {
        if (lazy[k] == lazyZero) return;
        if(k*2+1 < SIZE*2-1) {
            lazy[2*k+1] = lazyMerge(lazy[2*k+1], lazy[k]);
            lazy[2*k+2] = lazyMerge(lazy[2*k+2], lazy[k]);
        }
        node[k] = nodeMergeWithLazy(node[k], lazy[k]);
        lazy[k] = lazyZero;
    }

    T add(int a, int b, T x, int k, int l, int r) {
        eval(k);

        if (b <= l || r <= a) return node[k];
        if (a <= l && r <= b) {
            lazy[k] = lazyMerge(lazy[k], x);
            return nodeMergeWithLazy(node[k], lazy[k]);
        }
        T t1 = add(a, b, x, 2*k+1, l, (l+r)/2), t2 = add(a, b, x, 2*k+2, (l+r)/2, r);
        node[k] = nodeMerge(t1, t2);
        return node[k];
    }

    T query(int a, int b, int k, int l, int r) {
        eval(k);

        if (a <= l && r <= b) return node[k];
        bool left = !((l+r)/2 <= a || b <= l), right = !(r <= 1 || b <= (l+r)/2);
        if (left && right) {
            T t1 = query(a, b, 2*k+1, l, (l+r)/2), t2 = query(a, b, 2*k+2, (l+r)/2, r);
            return nodeMerge(t1, t2);
        }
        if (left) return query(a, b, 2*k+1, l, (l+r)/2);
        return query(a, b, 2*k+2, (l+r)/2, r);
    }

    void init(int n) {
        SIZE = 1;
        while (SIZE < n) SIZE <<= 1;
        node.resize(SIZE<<1, nodeZero);
        lazy.resize(SIZE<<1, lazyZero);
    }

public:
    LazySegmentTree() {}
    LazySegmentTree(
        int n,
        T nodeZero,
        T lazyZero,
        function<T(T&, T&)> nodeMerge,
        function<T(T&, T&)> lazyMerge,
        function<T(T&, T&)> nodeMergeWithLazy
    ) : nodeZero(nodeZero),
        lazyZero(lazyZero),
        nodeMerge(nodeMerge),
        lazyMerge(lazyMerge),
        nodeMergeWithLazy(nodeMergeWithLazy) {
            init(n);
    }

    T add(int a, int b, T x) { return add(a, b, x, 0, 0, SIZE); }
    T query(int a, int b) { return query(a, b, 0, 0, SIZE); }

    void set(int a, T x) {
        function<T(T&, T&)> tmp1 = lazyMerge,
                            tmp2 = nodeMergeWithLazy;
        lazyMerge = nodeMergeWithLazy = add_function;
        add(a, a+1, x-query(a, a+1));
        lazyMerge = tmp1;
        nodeMergeWithLazy = tmp2;
    }
    
    T operator[](int i) { return query(i, i+1); }
 
    LazySegmentTree<T> maxTree(int n) const {
        LazySegmentTree<T> ret(
            n,
            numeric_limits<T>::lowest(),
            T(0),
            [](T& l, T& r) { return max(l,r); },
            [](T& l, T& r) { return l+r; },
            [](T& l, T& r) { return l+r; });
        return ret;
    }

    LazySegmentTree<T> minTree(int n) const {
        LazySegmentTree<T> ret(
            n,
            numeric_limits<T>::max(),
            T(0),
            [](T& l, T& r) { return min(l,r); },
            [](T& l, T& r) { return l+r; },
            [](T& l, T& r) { return l+r; });
        return ret;
    }

    LazySegmentTree<T> sumTree(int n) const {
        LazySegmentTree<T> ret(
            n,
            T(0),
            T(0),
            [](T& l, T& r) { return l+r; },
            [](T& l, T& r) { return l+r; },
            [](T& l, T& r) { return l+r; });
        return ret;
    }
};

#define MaxTree(t, n) LazySegmentTree<t>().maxTree(n);
#define MinTree(t, n) LazySegmentTree<t>().minTree(n);
#define SumTree(t, n) LazySegmentTree<t>().sumTree(n);