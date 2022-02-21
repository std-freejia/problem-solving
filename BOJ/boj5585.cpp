/** 거스름돈
 * https://www.acmicpc.net/problem/5585
 * http://boj.kr/ddbf43f66f784f39a76760fa52482d67
 * */
#include <bits/stdc++.h>
using namespace std;

int n, cnt, i;
int arr[7] = {500, 100, 50, 10, 5, 1};

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;

  n *= (-1); n += 1000;

  while(n != 0){
    if(n - arr[i] >= 0){
      cnt++;
      n -= arr[i];
    }else i++; // 다른 동전으로 바꾼다
  }

  cout << cnt;
  return 0;
}