/**  하얀 칸
 * https://www.acmicpc.net/problem/1100
 * http://boj.kr/9da24812cc92495eb85aaa14b7e84b4f
 * */
#include <bits/stdc++.h>
using namespace std;

string st;
int answer;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  for (int i = 0; i < 8; i++){
    cin >> st;
    for (int j = 0; j < 8; j++) {
      if((i + j) % 2 == 0 && st[j] == 'F') answer++;
    }
  }
  cout << answer;

  return 0;
}