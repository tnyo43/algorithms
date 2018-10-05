#include <iostream>

using namespace std;

typedef long long ll;

bool is_prime(ll n) {
  if (n==1) return false;
  if (n==2) return true;
  if (n%2 == 0) return false;
  ll k = 3;
  while (k*k <= n) {
    if (n%k == 0) return false;
    k += 2;
  }
  return true;
} 

int main () {

  ll N;
  cin >> N;
  cout << (is_prime(N)?"YES":"NO") << endl;
  return 0;

}
