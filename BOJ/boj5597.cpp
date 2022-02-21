/** 과제 안 내신 분..?
 * https://www.acmicpc.net/problem/5597
 * http://boj.kr/bee146a15d22421d8b48f07c98492a7a
 * */
#include <bits/stdc++.h>
using namespace std;

int check[32];
int n;
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  for(int i = 1; i <= 28; i++){ // 28개 입력받음
    cin >> n; check[n] = 1;
  }
  for(int i = 1; i <= 30; i++){ // 30개 검사
    if(check[i] == 0) cout << i << '\n';
  }
  return 0;
}