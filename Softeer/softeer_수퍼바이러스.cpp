#include <bits/stdc++.h>
#define MOD 1000000007
#define ll long long
using namespace std;

ll k, p, n;

ll cal(ll cnt){ // cnt 초 동안  x배
  if(cnt == 1) return p;
  ll result = cal(cnt/2);

  result = result * result % MOD; // 짝수 승
  if(cnt % 2 == 1) result = (result * p) % MOD; // 홀수 승은 p를 한번 더 곱한다.
  return result;
}
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> k >> p >> n;

  // 0.1초 마다 p배 -> 1초마다 p*10배 -> 10*N초 동안 p배
  ll answer = (k * cal(10 * n)) % MOD;
  cout << answer;
  return 0;
}