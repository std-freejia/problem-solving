/** 민균이의 비밀번호
 https://www.acmicpc.net/problem/9933
 http://boj.kr/09ffb44082b2441baa282173a9b4b696
*/
#include <bits/stdc++.h>
using namespace std;

int n;
string st, answer;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;

  vector<string> v(n);
  for(int i = 0; i < n; i++){
    cin >> v[i];
  }
  for(int i = 0; i < n; i++){
    st = v[i];
    reverse(st.begin(), st.end());
    if( st == *find(v.begin(), v.end(), st)) {
      answer = st; break;
    }
  }
  int asize = answer.size();
  cout << asize << ' ' << answer[asize/2];

  return 0;
}