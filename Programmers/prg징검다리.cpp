#include <bits/stdc++.h>
using namespace std;

int solution(int distance, vector<int> rocks, int n) {

  sort(rocks.begin(), rocks.end()); // 오름차순 정렬
  int rlen = rocks.size(), answer = 0;
  int left = 0, right = distance;

  // 거리의 최소값이 mid 이하인지 검사한다.
  while(left <= right){
    int mid = (left + right ) /2; // 거리의 최소값
    int prev_idx = 0; // 직전 바위의 위치
    int remove_cnt = 0; // 제거한 바위 개수

    for(int i = 0; i < rlen; i++){
      if(rocks[i] - prev_idx < mid) { // 거리 차이가 mid 이하라면 제거한다.
        remove_cnt++;
      }else{
        prev_idx = rocks[i];
      }
    }
    // 도착지점과 마지막바위 간의 거리차이가 mid 이하라면 제거
    if(distance - prev_idx < mid) remove_cnt++;
    if(remove_cnt <= n) {
      answer = max(mid, answer); // n개 이하로 제거했다면, 거리의 최소값을 증가시켜본다.
      left = mid + 1;
    } else{
      right = mid - 1; // 거리의 최소값을 더 줄여본다.
    }
  }
  return answer;
}
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int distance = 25;
  vector<int> rocks{2, 14, 11, 21, 17};
  int n = 2;

  cout << solution(distance, rocks, n);
  return 0;
}