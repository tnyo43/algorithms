#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define REP(i,n) for (ll i = 0; i < n; ++i)
#define REPR(i,n) for (ll i = n - 1; i >= 0; --i)
#define FOR(i,n,m) for (ll i = n; i < m; ++i)

const int MAX = 1e5;

int N = 2e5+1;
vi node(N);

struct SegmentTree {
private:
    int n;
    vi node;

    int merge(int i) {
        node[i] = node[2*i+1] + node[2*i+2]; // 親は二つの子の和 
    }

    int sumRange(int i, int j, int idx, int left, int right) {
        if (i == left && j == right) // 探索終了、親を返す
        return node[idx];


        // 探索範囲を小さくできないか、中心を基準にして判定
        int mid = (left+right)/2;

        if (j <= mid) // 左半分で全てが得られる
        return sumRange(i, j, idx*2+1, left, mid);
        if (i > mid) // 右半分で全てが得られる
        return sumRange(i, j, idx*2+2, mid, right);

        // 探索範囲がmidの左右に存在するときは、midで分割してそれぞれの話を返す
        return sumRange(i, mid, idx*2+1, left, mid) + sumRange(mid, j, idx*2+2, mid, right);
    }

public:
    SegmentTree(vi v) {
        int size = v.size();
        n = 1;
        while (n < size) n <<= 1;
        node.resize(2*n-1, 0);

        REP (i, size) node[i+n-1] = v[i];
        REPR (i, n-1) merge(i);
    }

    int get(int i) { // 配列のi番目の要素を取得
        return node[i+n-1];
    }

    void update(int i, int x) { // i番目の要素をxに変更
        i += n-1;
        node[i] = x;
        while (i > 0) merge(i=(i-1)/2);
    }

    int sumRange(int i, int j) { // [i, j)の和を返す
        return sumRange(i, j, 0, 0, n);
    }
};

int main() {

    SegmentTree tree(node);
    int Q;
    cin >> Q;
    REP (q, Q) {
        int t, x;
        cin >> t >> x;
        if (t == 1) tree.update(x, tree.get(x)+1);
        else {
        int lo = 0, hi = N+1;
        while (hi-lo > 1) {
            int mid = (hi+lo)/2;
            if (tree.sumRange(0, mid) >= x) hi = mid;
            else lo = mid;
        }
        cout << lo << endl;
        tree.update(lo, tree.get(lo)-1);
        }
    }
    return 0;

}
