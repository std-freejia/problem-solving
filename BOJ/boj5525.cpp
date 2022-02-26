/** IOIOI
https://www.acmicpc.net/problem/5525
http://boj.kr/4cd4d8f379ef4b84bb5bf37282f46f73
*/
#include <bits/stdc++.h>
using namespace std;

int n, m, pattern, answer;
string s;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m >> s;

  for(int i = 0; i < m; i++){
    pattern = 0;
    if(s[i] == 'O') continue;
    while(s[i+1] == 'O' && s[i+2] == 'I'){
      pattern++;
      i+=2;
      if(pattern == n){
        answer++;
        pattern--; // 패턴이 연속할 수 있기 때문에 하나 뺴준다. IOIOI -> IOI가 2개.
      }
    }
  }
  cout << answer;
  return 0;
}
