/** 다리 놓기
 * https://www.acmicpc.net/problem/1010
 * http://boj.kr/2dd342c6f44849369f678383dea56dbf
 * */
#include <bits/stdc++.h>
using namespace std;

int t, n, m;
int a[32][32];
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  for(int i = 1; i <= 30; i++){
    a[i][i] = 1; a[1][i] = i;
  }
  for(int i = 2; i < 30; i++){
    for(int j = i+1; j < 30; j++){
      for(int k = 1; k < j; k++){
        a[i][j] += a[i-1][k];
      }
    }
  }
  cin >> t;
  while(t--){
    cin >> n >> m;
    cout << a[n][m] << '\n';
  }
  return 0;
}