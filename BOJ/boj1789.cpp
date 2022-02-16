/** 수들의 합
 * https://www.acmicpc.net/problem/1789
 * http://boj.kr/f535319076c24388b8971115fec87932
 */
#include <bits/stdc++.h>
using namespace std;

long long s;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> s;

  int num = 1; // 더할 수
  int cnt = 0; // 더한 수의 개수
  long long sum = 0; // 누적 합

  while(1){
    sum += num;
    cnt++;
    if(sum > s){
      cnt--;
      break;
    }
    num++;
  }
  cout << cnt;

  return 0;
}