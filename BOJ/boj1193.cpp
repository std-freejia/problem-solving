/** 분수찾기
 * https://www.acmicpc.net/problem/1193
 * http://boj.kr/da8b710976c249c2acdcc1be48ee55b1
 * */
#include <bits/stdc++.h>
using namespace std;

int n, num, i, mo, ja;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n; // n 번째 칸이 홀수 라인인지 짝수 라인인지 확인하기.

  i = 0; // i: 1, 2, 3, 4, ...
  while(num < n){
    i++;
    num += i;
  }
  // while문 종료 직후, num은 n보다 같거나 큰 수가 되어 있다.
  int diff = num - n; // 라인 시작점부터 이동할 숫자
  //cout << "diff:" << diff << '\n';

  if(i % 2){  // 홀수 라인 - 밑에서 대각선으로 위로 숫자 변화
    ja = 1 + diff; // 분모가 1로 시작 i로 종료.
    mo= i - diff; // 분자가 i로 시작, 1로 종료.
  }
  else { // 짝수 라인 - 위에서 왼쪽 대각선으로 아래로 숫자 변화
    ja = i - diff; // 분모 i로 시작 1로 종료
    mo = 1 + diff; // 분자 1로시작 i로 종료
  }
  cout << ja << '/' << mo;
  return 0;
}
