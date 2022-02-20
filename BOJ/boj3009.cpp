/** 네 번째 점 (XOR 연산 연습)
 * https://www.acmicpc.net/problem/3009
 * http://boj.kr/9ade740e77b945c7bebfed1e2a3737d8
 * */
#include <bits/stdc++.h>
using namespace std;

int a, b, aa, bb;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> a >> b;
  for(int i = 0; i < 2; i++) {
    cin >> aa >> bb;
    a ^= aa;
    b ^= bb;
  }
  cout << a << ' ' << b;
  return 0;
}