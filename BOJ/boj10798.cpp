/** 세로읽기
 https://www.acmicpc.net/problem/10798
 http://boj.kr/10baf570572b4515bbd297c6eae52beb
*/
#include <bits/stdc++.h>
using namespace std;

char a[6][16];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  for(int i = 0; i < 5; i++) cin >> a[i];
  int w = sizeof(a[0]);

  for(int i = 0; i < w; i++) {
    for(int j = 0; j < 5; j++){
      if(a[j][i]) cout << a[j][i];
    }
  }

  return 0;
}
