/** 수 정렬하기 3
 https://www.acmicpc.net/problem/10989
 http://boj.kr/f09a8cdb6f4441528b47928e94afe138
 */
#include <bits/stdc++.h>
using namespace std;

int n, num;
int arr[10002];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  while(n--){
    cin >> num;
    arr[num]++;
  }
  for(int i = 0; i < 10001; i++){
    for(int j = 0; j < arr[i]; j++){
      cout << i << '\n';
    }
  }
  return 0;
}