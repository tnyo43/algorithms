# Graph Algorithms

# 最短路

グラフのS地点からT地点まで最短のコストで行く探索。
最大コストを知りたいときは-1かけたりする。よくオーバーフローするので制約に気をつけるか無難にlong longを使う。

### Warshall Floyd
N個のノードのエッジをN*Nの2次元配列に保存する。a→bよりa→c→bの方が早い時に更新する。更新をN回行うと全てが最短路のコストになっていることが保証されている。
一回更新が終わるとそれ以降は参照するだけなので、スタート地点がわからないときはダイクストラよりも早いことがある。（使用例はそれ）

##### 計算量　
- V：ノードの数

O(V^3)

##### 使用例　
[AtCoder ABC012 D バスと避けられない運命](https://beta.atcoder.jp/contests/abc012/submissions/3187821)

### Dijkstra
注目している点から他のノードに行くとき、更新できるならその点を優先度付きキューに保存する。コストの小さいものから順に注目していくので、
キューがからになるまで更新を繰り返すと最短経路が見つかる。多分一番早い。ただし悲負数限定。

##### 計算量
- V：ノードの数
- E：エッジの数

O((E+V)logV)

##### 使用例
[AtCoder ABC012 D バスと避けられない運命](https://beta.atcoder.jp/contests/abc012/submissions/3187768)

[AtCoder ARC064 E Cosmic Rays](https://beta.atcoder.jp/contests/arc064/submissions/3196615)

### Bellman Ford
コストに負数があっても対応できる。N-1回の更新で全てのノードに着く最小コストが計算できる。
ただし、延々とコストが小さくなるループが存在するときは更新が終わらず、これも検知することができる。

##### 計算量
- V：ノードの数
- E：エッジの数

O(EV)

##### 使用例
[AtCoder ABC061 D Score Attack](https://beta.atcoder.jp/contests/abc061/submissions/3189628)


# グラフネットワークフロー

## 最大流量
二つのノードs、tの間に複数の道があり、それらを使って通れる最大値を求める問題

### Ford Fulkerson法
目的地まで目的地までの道があれば流せるだけ流し、その分だけエッジの容量を小さくする。そのかわりに逆方向への容量を大きくする。これで常に最大流に達するための経路を確保できる。目的地への道がなくなるまで繰り返し、それまでの流量の合計が最大流量となる

##### 計算量
- E：エッジの数
- F：最大フロー

O(EF)

##### 使用例
[AtCoder ABC010 D 浮気予防](https://beta.atcoder.jp/contests/abc010/submissions/3195877)

### Dinic法
基本的にはFord Fulkerson法と同じ。先にBFSで出発地点からの距離を求めて無駄な遠回りをしないように改善されている。最大流量の見立てが大きい時にはFord Fulkerson法よりもこっちの方がいい気がする。

##### 計算量
- V：ノードの数
- E：エッジの数

O(EV^2)

##### 使用例
[AtCoder ABC010 D 浮気予防](https://beta.atcoder.jp/contests/abc010/submissions/3196255)
