/** 셀프 넘버
 * https://www.acmicpc.net/problem/4673
 * http://boj.kr/59766fef7ae1474abae81c6655b9a3b5
 * */
#include <bits/stdc++.h>
#define limit 10002
using namespace std;

bool arr[limit];

int check(int num){
  int sum = num;
  while(num != 0){
    sum += num % 10;
    num /= 10;
  }
  return sum;
}
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  for(int i = 1; i <limit; i++){
    int idx = check(i);
    if(idx <= limit) arr[idx] = true;
  }

  for(int i = 1; i <limit; i++) if(!arr[i]) cout << i << '\n';
  return 0;
}