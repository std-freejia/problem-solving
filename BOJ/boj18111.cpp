/** 마인크래프트
 https://www.acmicpc.net/problem/18111
 http://boj.kr/8dcf32c6046a462499dd56f1187246bf
 */
#include <bits/stdc++.h>
using namespace std;

int n, m, b;
int min_height = 256, max_height = 0;
int min_time = 1e9, block_height = 0;
int ground[502][502];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m >> b;

  for(int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) { // 블록의 최소 높이와 최대 높이 구하기
      cin >> ground[i][j];
      min_height = min(min_height, ground[i][j]);
      max_height = max(max_height, ground[i][j]);
    }
  }

  // 목표 높이 h : 최소 높이~ 최대 높이 모두 검사한다.
  for(int h = min_height; h <= max_height; h++){
    int temp_time = 0;
    int inven = b;
    int diff = 0;  // 목표높이 h와 현재 땅의 높이 차이

    for(int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) { // 블록의 최소 높이와 최대 높이 구하기

        diff = abs(ground[i][j] - h);
        if(ground[i][j] < h) {  // 낮다면, 시간 2씩 더하고, 인벤에서 꺼내서 쌓아준다
          temp_time += diff;
          inven -= diff;
        }
        else if (ground[i][j] > h){ // 높다면, 시간 1씩 더하고, 인벤에 옮긴다
          temp_time += (2 * diff);
          inven += diff;
        }
      }
    }
    if(inven >= 0){
      min_time = min(min_time, temp_time);
      // 답이 여러 개 있다면 그중에서 땅의 높이가 가장 높은 것을 출력
      if(temp_time == min_time) block_height = max(block_height, h);
    }
  }

  cout << min_time << " " << block_height;

  return 0;
}