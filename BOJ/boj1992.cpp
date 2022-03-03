/** 쿼드트리
 https://www.acmicpc.net/problem/1992
 http://boj.kr/c9aa85af382d49ba84bd37b86c4f728c
 */
#include <bits/stdc++.h>
using namespace std;

int n;
string st[64];

void recur(int h, int w, int len){ // 시작점 h,w 한 변의 길이

  char ch = st[h][w];

  for(int i = h; i < h+len; i++){
    for(int j = w; j < w+len; j++){
      if(ch != st[i][j]) {
        cout << '(';
        recur(h, w, len/2);
        recur(h, w + len/2, len/2);
        recur(h + len/2, w, len/2);
        recur(h + len/2, w + len/2, len/2);
        cout << ')';
        return;
      }
    }
  }
  cout << ch;
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for(int i = 0; i < n; i++) cin >> st[i];
  recur(0, 0, n);
  return 0;
}
