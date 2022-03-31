#include <bits/stdc++.h>
using namespace std;

int solution(string name) {
  int answer = 0;
  // 위아래로 변환 횟수
  for(auto n : name) answer += min(n-'A', 'Z'- n + 1);

  int len = name.length();
  int move = len - 1; // 이동 최대 거리
  int next = 0;

  for(int i = 0; i < len; i++){
    next = i + 1;
    while(next < len && name[next] == 'A') next++; // 변환할 타겟 문자의 인덱스

    int move_min = i + (len - next) + min(i, len-next);
    move = min(move, move_min);
  }
  answer += move;

  return answer;
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  string name = "JEROEN";
  cout << solution(name);

  return 0;
}
