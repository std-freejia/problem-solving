/** 색종이 만들기
 https://www.acmicpc.net/problem/2630
 http://boj.kr/721df2a2bc4c4fc9a5a593a662668c7b
 * */
#include <bits/stdc++.h>
using namespace std;

int N, white_cnt, blue_cnt; // 하양 0, 파랑 1 로 표시
int arr[129][129];

void check(int x, int y, int len){ // 행, 열, 한 변 길이

  int color = arr[x][y];
  for(int i = x; i < x+len; i++){ // 행
    for(int j = y; j < y+len; j++){ // 열
      if(color != arr[i][j]){
        check(x, y, len/2);
        check(x, y + len/2, len/2);
        check(x + len/2, y, len/2);
        check(x + len/2, y + len/2, len/2);
        return;
      }
    }
  }
  if(color == 1) blue_cnt++;
  else white_cnt++;
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;

  for(int i = 0; i < N; i++) // 입력 받기
    for(int j = 0; j < N; j++)
      cin >> arr[i][j];

  check(0, 0, N);
  cout << white_cnt << '\n' << blue_cnt;
  return 0;
}