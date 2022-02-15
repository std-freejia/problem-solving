/** 더하기 사이클
 https://www.acmicpc.net/problem/1110
 http://boj.kr/f186e265c0dd45fbb0e0feec3798e8af
 */
#include <bits/stdc++.h>
using namespace std;

int input, cnt, n;
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> input;
  n = input;
  while(1){
    n = ((n % 10) * 10) + ((n / 10) + (n % 10)) % 10;
    cnt++;
    if(n == input) break;
  }
  cout << cnt;
  return 0;
}