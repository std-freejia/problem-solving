/** 뒤집기
 * https://www.acmicpc.net/problem/1439
 * http://boj.kr/08be6e59f5b04cf6904ae08973a1d52b
*/
#include <bits/stdc++.h>
using namespace std;

string s;
int cnt[2]; // 0의 개수, 1의 개수 카운팅

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> s;

  cnt[s[0] - '0']++;  // 첫 문자가 0인지 1인지.
  char ch = s[0]; // 첫 문자

  for(int i = 1; i < s.size(); i++){
    if(ch != s[i]) { // 이전 문자와 다르면, 키운팅
      ch = s[i]; cnt[s[i] - '0']++;
    }
  }
  cout << min(cnt[0], cnt[1]);
  return 0;
}
