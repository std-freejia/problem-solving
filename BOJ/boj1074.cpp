/** Z
 * https://www.acmicpc.net/problem/1074
 * http://boj.kr/21c1c45b6c6349b689db5186faf9d6a3
*/
#include <bits/stdc++.h>
using namespace std;

int N, r, c, answer;

void rec(int n, int row, int col){

  if(n == 0) return;
  int len = pow(2, n-1);  // 사분면 한 변의 길이
  int square_cnt  = len * len;  // 사분면 하나가 포함하는 칸 수

  if(row / len == 0 && col / len == 0){ // 1사분면
    rec(n-1, row % len, col % len);
  }
  else if(row / len == 0 && col / len == 1){ // 2사분면
    answer += square_cnt;
    rec(n-1, row % len, col % len);
  }
  else if(row / len == 1 && col / len == 0){ // 3사분면
    answer += square_cnt * 2;
    rec(n-1, row % len, col % len);
  }
  else if(row / len == 1 && col / len == 1){ // 4사분면
    answer += square_cnt * 3;
    rec(n-1, row % len, col % len);
  }
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> r >> c;

  rec(N, r, c);
  cout << answer;

  return 0;
}