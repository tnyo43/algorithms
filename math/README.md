# 数学問題
数学問題っぽいアルゴリズム

### mod
整数問題をまとめたライブラリ。ある素数を法としてあまりを求めるとき、その組み合わせの数を求めるのに使える。フェルマーの小定理を使っている。前処理にO(N)かかり、それ以降はO(1)で実行できる。以下は全てmod pの中での計算結果になる

- fact[n]：n!
- finv[n]：n!の逆数
- inv[n]：1/n
- nCk(n, k)：nCk（組み合わせ計算）
- nHk(n, k)：nHk（重複を含む組み合わせ計算）

##### 計算量
- N：組み合わせを考えたい数の上限

###### 初期化
O(N)

###### クエリ
O(1)

##### 使用例
[AtCoder ABC 021 D 多重ループ](https://beta.atcoder.jp/contests/abc021/submissions/3227162)

[AtCoder ABC 110 D Factorization](https://beta.atcoder.jp/contests/abc110/submissions/3254110)

### fibonacci
フィボナッチ数列を求めるライブラリ（mod p）。行列の高速冪乗計算でO(logN)で計算可能。入力をlong longにして、10^18くらいまで計算可能で十分高速（pはint）

##### 計算量
- N：求めたいフィボナッチ数列の要素

O(logN)

##### 使用例
なし（たぶんあってる）


