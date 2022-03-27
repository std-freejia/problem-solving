/** 문자열
https://www.acmicpc.net/problem/1120
http://boj.kr/dca47c16269945e7b8ffb6ceb41aeae3
*/
#include <bits/stdc++.h>
using namespace std;

string x, y;
int diff_cnt = 50;
int cnt;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> x >> y;
  int diff = y.length() - x.length();

  for(int i = 0; i <= diff; i++){
    cnt = 0;
    for(int j = 0; j < x.length(); j++){
      if(x[j] != y[j+i]) cnt++;
    }
    diff_cnt = min(cnt, diff_cnt);
  }
  cout << diff_cnt;
  return 0;
}
