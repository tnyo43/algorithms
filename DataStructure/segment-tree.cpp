#include <bits/stdc++.h>
using namespace std;

enum QUERY_GET { SUM, MAXIMUM, MINIMUM };
template <class T = int>
class SegmentTree {
private:
    int ARY_SIZE;
    T initVal;
    std::vector<T> ary;
    std::function<T(T&, T&)> merge;
 
    void init(int n, QUERY_GET qtype) {
        switch (qtype) {
        case SUM:
            initVal = 0;
            merge = [](T& l, T& r) {return l + r; };
            break;
        case MAXIMUM:
            initVal = std::numeric_limits<T>::lowest();
            merge = [](T& l, T& r) {return (l > r) ? l : r; };
            break;
        case MINIMUM:
            initVal = std::numeric_limits<T>::max();
            merge = [](T& l, T& r) {return (l < r) ? l : r; };
            break;
        default: struct INVALID_QUERY_TYPE_ERROR {}; throw INVALID_QUERY_TYPE_ERROR(); break;
        }
        init(n);
    }
    void init(int n) {
        while (ARY_SIZE < n) ARY_SIZE <<= 1;
        ary.resize(ARY_SIZE << 1, initVal);
    }
public:
    SegmentTree() {}
    SegmentTree(int n, QUERY_GET qtype) : ARY_SIZE(1) { init(n, qtype); }
    SegmentTree(int n, T initVal, std::function<T(T&, T&)> f) : ARY_SIZE(1), initVal(initVal), merge(f) { init(n); }
 
    inline void update(int i, T val) {
        i += ARY_SIZE;
        ary[i] = val;
        while (i > 1) {
            i >>= 1;
            ary[i] = merge(ary[i << 1], ary[(i << 1) + 1]);
        }
    }

    inline void add(int i, T val) {
        update(i, ary[i + ARY_SIZE] + val);
    }

    inline T query(int l, int r) {
        if (l >= r) return initVal;
        T vl = initVal, vr = initVal;
        for (l += ARY_SIZE, r += ARY_SIZE; l != r; l >>= 1, r >>= 1) {
            if (l & 1) vl = merge(vl, ary[l++]);
            if (r & 1) vr = merge(ary[--r], vr);
        }
        return merge(vl, vr);
    }

    T operator[](int i) { return ary[i + ARY_SIZE]; }
 
    void debugShow() {
        for (int i = ARY_SIZE; i < ARY_SIZE << 1; ++i) std::cerr << ary[i] << " ";
        std::cerr << "\n";
    }
};

int N;
SegmentTree<int> tree_sum, tree_max, tree_min;

int main() {
    cin >> N;
    tree_min = SegmentTree<int>(N, MINIMUM);
    tree_max = SegmentTree<int>(N, MAXIMUM);
    tree_sum = SegmentTree<int>(N, SUM);
}
