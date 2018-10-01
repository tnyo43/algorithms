# データ構造
データ構造に関するアルゴリズム
## Union Find

### Union Find
二つのノードが同じグループに属するかを判別する。共通の親を持つなら同じグループ。速い（アッカーマン関数の逆関数A(x)オーダー）。いろんなアルゴリズムの補助に使われたりする。

##### 計算量
- N：ノード数

O(A(N))

##### 使用例
[AtCoder ATC001 B Union Find](https://beta.atcoder.jp/contests/atc001/submissions/3194816)

### 重み付きUnion Find
親との距離を持っておくことで、同じ木に属するノード同士の距離を測ることができる。木を合わせるときに親との相対的な重みを更新、同じ木同士のときは重みを計算できる。

##### 計算量
- N：ノード数

O(A(N))

##### 使用例
[AtCoder ABC087 D People on a Line](https://beta.atcoder.jp/contests/abc087/submissions/3206886)


## Segment Tree

### Segment Tree
完全二分木を用いて数列の部分和を高速で計算する。一度O(N)で初期化すれば、更新、計算がO(logN)でできる。

##### 計算量
- N：ノード数

###### 初期化
O(N)

###### 更新・計算
O(logN)

##### 使用例
[AtCoder ARC 033 C - データ構造](https://beta.atcoder.jp/contests/arc033/submissions/3208430)


### RMQ
Range Minimum Query。Segment Treeを用いて区間の最小の値をO(logN)で計算できる。
##### 計算量
- N：ノード数

###### 初期化
O(N)

###### 更新・計算
O(logN)

##### 使用例
なし


## Others

### LCA
木の二つのノードのLowest Common Ancestor、共通のもっとも深くにある親を見つける。直感的には枝分かれしたポイントを探す。LCAは一方のノードにもなりうる。あるノードの1つ上のノードを記憶するようにすると高速で2つ上のノードも見れる。これにより2^k先のノードを高速で参照できるようになるので、あるノードのN個上のノードはO(logN)で確認できる。

##### 計算量
- N：ノード数
###### 前処理
O(NlogN)
###### クエリ
O(logN)

##### 使用例
[AtCoder ABC 014 D 閉路](https://beta.atcoder.jp/contests/abc014/submissions/3213922)
