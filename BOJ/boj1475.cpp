/** 방 번호
 https://www.acmicpc.net/problem/1475
 http://boj.kr/fcde87a40d3d4d6a8a1bedbc1e697b1b
 * */
#include <bits/stdc++.h>
using namespace std;

int n, cnt;
int v[11];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  string s = to_string(n);
  for(auto num : s){
    v[num - '0']++;
  }

  int temp_sum = 0, temp_cnt = 0; // 9와 6만 센다

  for(int i = 0; i < 10; i++){
    cout << v[i] << ' ';
    if(i == 9 || i == 6) temp_sum += v[i];
    else cnt = max(cnt , v[i]);
  }

  if( temp_sum % 2 == 0) temp_cnt = temp_sum / 2;
  else temp_cnt = (temp_sum + 1) / 2;

  cout << max(cnt, temp_cnt);

  return 0;
}