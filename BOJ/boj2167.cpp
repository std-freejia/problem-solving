/** 2차원 배열의 합
 https://www.acmicpc.net/problem/2167
 http://boj.kr/1455af54a75c4f51b96f129c251c9538
 */
#include <bits/stdc++.h>
using namespace std;

int n, m, k, i, j, x, y;
int arr[302][302];

long long check(){
  long long sum = 0;
  for(int a = i; a <= x; a++){
    for(int b = j; b <= y; b++){
      sum += arr[a][b];
    }
  }
  return sum;
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= m; j++){
      cin >> arr[i][j];
    }
  }
  cin >> k;
  while(k--){
    cin >> i >> j >> x >> y;
    cout << check() << '\n';
  }
  return 0;
}