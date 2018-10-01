#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

#define REP(i, n) for (ll i = 0; i < (n); ++i)

int N;
int a; // ループのスタート地点
vi nexts;

ii circle_find(int s) {
  int usa = s; // うさぎさんの位置
  int kam = s; // 亀さんの位置
  int steps = 0;
  while (1) {
    usa = nexts[nexts[usa]]; // うさぎが2つ進む
    kam = nexts[kam];
    steps++;
    if (usa == kam) break;
  }

  int count = 0;
  while (1) {
    usa = nexts[usa]; // 亀に会うまで1つずつ動く
    count++;
    if (usa == kam) break;
  }

  return make_pair(steps, count);
}

int main() {

  cin >> N >> a;
  a--;
  nexts.resize(N);
  REP (i, N) {
    cin >> nexts[i];
    nexts[i]--;
  }

  ii res = circle_find(a);
  int s = res.first;
  int l = res.second;

  cout << s << " " << l << endl;
  return 0;
}
