/** 약수
https://www.acmicpc.net/problem/1037
http://boj.kr/caa576f5ac274275b725adedfb50c828
*/
#include <bits/stdc++.h>
using namespace std;

long long n, num;
vector<int> v;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> num;
    v.push_back(num);
  }

  sort(v.begin(), v.end());
  if(n % 2 == 0) cout << v[0] * v[n-1];
  else cout << v[n/2] * v[n/2];
  return 0;
}
