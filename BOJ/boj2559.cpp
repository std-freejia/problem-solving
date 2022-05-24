#include <bits/stdc++.h>
using namespace std;

// 백준 2556번 수열 http://boj.kr/a717629cc3b94165a91246988975b510
int n, k, start_idx, end_idx;
long long sum, sum_temp;
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> k;
  vector<int> v(n);

  for(int i = 0; i < n; i++) cin >> v[i];

  // 처음에 k개의 누적합 구하기
  for(int i = 0; i < k; i++) sum_temp += v[i];
  start_idx = 0, end_idx = k-1;

  sum = sum_temp;
  while(end_idx < n){
    sum_temp -= v[start_idx++]; // 현재 인덱스 값 빼기, 인덱스 증가
    if(end_idx + 1 == n) break;
    sum_temp += v[++end_idx];   // 인덱스 증가시킨 후 그 인덱스 값 더하기
    sum = max(sum_temp, sum);
  }
  cout << sum;
  return 0;
}