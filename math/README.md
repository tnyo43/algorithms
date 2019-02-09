# 数学問題
数学問題っぽいアルゴリズム

### 階乗、逆元、nCk、nHk
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

### フィボナッチ
フィボナッチ数列を求めるライブラリ（mod p）。行列の高速冪乗計算でO(logN)で計算可能。入力をlong longにして、10^18くらいまで計算可能で十分高速（pはint）

##### 計算量
- N：求めたいフィボナッチ数列の要素

O(logN)

##### 検証
[AOJ フィボナッチ数列](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_10_A&lang=jp)

## 最大公約数・最小公倍数

### 最大公約数（ユークリッドの互除法）
ユークリッドの互除法を用いて最大公約数を求める。除数を剰余で割った剰余を...と繰り返し、高速で求められる。

##### 計算量
- N, M：最大公約数を求めたい数の組

O(log(min(N, M)))

##### 使用例

[AtCoder ABC 109 C スキップ](https://beta.atcoder.jp/contests/abc109/submissions/me)

### 最小公倍数
最大公約数を用いて最小公倍数を求める。二つの整数a,bとその最大公約数gについて、a,bの最小公倍数はab/gになる。最後の計算はO(1)なので、全体の計算量は最大公倍数を求めるO(log(min(N,M)))。

##### 計算量
- N, M：最小公倍数を求めたい数の組

O(log(min(N, M)))

##### 使用例
[AtCoder ABC070 C Multiple Clocks](https://beta.atcoder.jp/contests/abc070/submissions/3329136)

### 拡張ユークリッドの互除法
ユークリッドの互除法を応用して、二つの整数a,bとその最大公約数gについて"ax + by = g"なるxとyを求める。

##### 計算量
- N, M：最大公約数を求めたい数の組

O(log(min(N, M)))

##### 検証
[AOJ 拡張ユークリッドの互除法](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_E&lang=jp)


## 素数
### 素数判定
Nが素数かどうかをsqrt(N)までチェックすることで確かめる。申し訳程度に偶数の判定を先にしてあるのでちょっと効率化したが、そんなに変わらなさそう。最適化をするかも（あまり必要性を感じないが）

##### 計算量
- N；判定したい整数

O(sqrt(N))

##### 使用例
[AtCoder ARC017 A 素数、コンテスト、素数](https://beta.atcoder.jp/contests/arc017/submissions/3329239)

### 素因数分解
与えられた数を素因数分解する。<素因数、個数>のpairのvectorを返す。与えられたNの平方根まで数を確認しながら、因数に持つならその数で割れる回数をカウントする。

##### 計算量
- N：素因数分解したい数

O(sqrt(N)logN)

### 約数
ある数字の約数を列挙する。素因数分解し、各要素の出現数の組み合わせを全通り計算する。最後にソートして昇順にする。最後にソートするが、そもそも要素の数がlogNくらいに小さくなるので、素因数分解の計算が一番時間がかかる（と思う）

##### 計算量
- N：約数を求めたい数

O(sqrt(N)logN)

##### 使用例
[AtCoder ABC 112 D Partition](https://beta.atcoder.jp/contests/abc112/submissions/3355926)


##### 使用例
[AtCoder ABC096 D Five, Five Everywhere](https://beta.atcoder.jp/contests/abc096/submissions/3334354)

### エラトステネスの篩
素数の表を作成する。最大値Nのsqrt(N)まで素数か否かを判定する。最適化してないのでO(NloglogN)よりちょっと大きい

##### 計算量
- N：求めたい素数の最大値

O(Nloglog(N))

##### 使用例
[AtCoder ABC096 D Five, Five Everywhere](https://beta.atcoder.jp/contests/abc096/submissions/3334354)

### Baby-Step Giant-Step
離散対数問題を解くアルゴリズム。とくに、g^x = y mod pを解く

##### 計算量
- p：法をとる素数

O(sqrt(p)log p)