/** 명령 프롬프트
 * https://www.acmicpc.net/problem/1032
 * http://boj.kr/f50745fe75c042b19f172019912c61d1
 * */
#include <bits/stdc++.h>
using namespace std;

int n;
string tempstr, answer;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> answer;
  while(n--) {
    cin >> tempstr;
    for(int i = 0; i < tempstr.size(); i++)
      if(tempstr[i] != answer[i]) answer[i] = '?';
  }
  cout << answer;
  return 0;
}