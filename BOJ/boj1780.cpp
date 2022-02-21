/** 종이의 개수
 * https://www.acmicpc.net/problem/1780
 * http://boj.kr/1740a186a0334463ba4760c91a7db017
 * */
#include <bits/stdc++.h>
using namespace std;

int n;
int arr[3000][3000];
int answer[3];

bool check(int starti, int endj, int size){ // 전부 같은 색깔인지 검사
  int color = arr[starti][endj];
  for(int i = starti; i < (starti+size); i++){
    for(int j = endj; j < (endj+size); j++) {
      if (color != arr[i][j]) return false;
    }
  }
  return true;
}

void div_paper(int x, int y, int len){
  if(check(x, y, len)){
    answer[arr[x][y]]++; return;
  }

  int div_len = len / 3; // len == 9, div_len == 3
  for(int i = 0; i <3; i++){
    for(int j = 0; j <3; j++){ // 좌표에 0, 3, 6을 더한 시작점에서 다시 검사한다.
      div_paper(x + i*div_len, y + j*div_len, div_len);
    }
  }
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for(int i = 0; i < n; i++){
    for(int j = 0; j <n; j++){
      cin >> arr[i][j]; arr[i][j]++; // 양수로 만들기
    }
  }

  div_paper(0,0,n);
  for(auto c : answer) cout << c << '\n';

  return 0;
}