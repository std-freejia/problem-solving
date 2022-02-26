/** 완전제곱수
https://www.acmicpc.net/problem/1977
http://boj.kr/20b5bd7e9cee48aca6a542bcf2eabc61
*/
#include <bits/stdc++.h>
using namespace std;

int m, n, total_sum;
int minnum= 1e9;
int arr[100001];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> m >> n;
  int num = 1;
  while(num * num <= n){
    arr[num * num] = 1;
    num++;
  }

  for(int i = m; i <= n; i++){
    if(arr[i]) {
      total_sum += i;
      minnum = min(minnum, i);
    }
  }
  if(total_sum == 0) cout << -1;
  else cout << total_sum << '\n' << minnum;

  return 0;
}