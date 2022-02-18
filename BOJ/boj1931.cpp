/** 회의실 배정
 https://www.acmicpc.net/problem/1931
 http://boj.kr/44982c2f9d57425e91c7209c2d527bb4
 */
#include <bits/stdc++.h>
using namespace std;

int n, cnt;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  vector<pair<int,int>> v(n);

  for(int i = 0; i < n; i++){
    cin >> v[i].second >> v[i].first; // <종료시간, 시작시간>
  }
  sort(v.begin(), v.end());  // '시작시간' 기준으로 정렬

  int temptime = 0;
  for(int i = 0; i < n; i++){
    if(temptime <= v[i].second){
      temptime = v[i].first;
      cnt++;
    }
  }
  cout << cnt;
  return 0;
}
