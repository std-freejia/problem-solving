/** 뒤집힌 덧셈
http://boj.kr/b72c7c22881643f6a2cc4b706d106384
https://www.acmicpc.net/problem/1357
 */
#include <bits/stdc++.h>
using namespace std;

string x, y, st;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> x >> y;
  reverse(x.begin(), x.end());
  reverse(y.begin(), y.end());
  int xx = stoi(x);
  int yy = stoi(y);
  st = to_string(xx+yy);
  reverse(st.begin(), st.end());
  cout << stoi(st);
  return 0;
}