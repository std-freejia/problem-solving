/**  랜선 자르기
 https://www.acmicpc.net/problem/1654
 https://www.acmicpc.net/source/39046420
 */
#include <bits/stdc++.h>
using namespace std;

int k, n; // 가지고있는 랜선 개수, 필요한 개수
int maxlen;
int line[10002];
long long mid, high, low;

int count(int t){
  int cnt = 0 ;
  for(int i = 0; i < k; i++) cnt += (line[i] / t);
  return cnt;
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> k >> n;

  for(int i = 0; i < k; i++){
    cin >> line[i];
    if(maxlen < line[i]) maxlen = line[i];
  }

  high = maxlen, low = 1;
  long long answer = 0;

  while(low <= high){
    mid = (low + high)/ 2;
    int cnt = count(mid);

    if(cnt >= n) {
      low = mid + 1;
      if(answer < mid) answer = mid;
    }
    else {
      high = mid - 1;
    }
  }

  cout << answer;
  return 0;
}