/** Four Squares
 https://www.acmicpc.net/problem/17626
 http://boj.kr/095ad9ab9484418f9595b9dddf08aee5
*/
#include <bits/stdc++.h>
using namespace std;

int dp[50002];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  dp[1] = 1; // dp[0] == 0

  for(int i = 1; i <= n; i++){
    dp[i] = dp[1] + dp[i-1];
    for(int j = 2; j * j <= i; j++) // i == j*j 이라면 개수가 1개
      dp[i] = min(dp[i-j*j] + 1, dp[i]);
  }
  cout << dp[n];
  return 0;
}