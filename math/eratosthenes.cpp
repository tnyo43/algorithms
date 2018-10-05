#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;

vi getPrimes(int n) {
  /*
   * n以下の素数を全て返す
   * アルゴリズムにはエラトステネスの篩を用いる
   */
  vi res;
  bool isPrime[n+1];
  isPrime[0] = isPrime[1] = false;
  for (int i = 2; i <= n; i++) isPrime[i] = true;
  for (int i = 2; i <= n; i++) {
    if (isPrime[i]) {
      res.push_back(i);
      for (int j = i*2; j <= n; j += i) isPrime[j] = false;
    }
  }
  return res;
}


int main() {

  vi primes = getPrimes(100000);
  for (int i = 0; i < primes.size(); i++) cout << primes[i] << " ";
  cout << endl;

}
