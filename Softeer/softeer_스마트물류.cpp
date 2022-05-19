#include <bits/stdc++.h>
using namespace std;

int n, k, answer;
string line;
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> k >> line;

  for(int i = 0; i < n; i++) {
    if('P' == line[i]){ // 로봇이라면, 양쪽을 확인
      for(int j = i-k; j <= i+k; j++){ // i 기준 양쪽을 본다.
        if(i == j || j < 0 || j >= n) continue;// 유효인덱스 검사
        if(line[j] == 'H') {
          line[j] = 'X';  answer++; break;
        }
      }
    }
  }
  cout <<  answer;
  return 0;
}