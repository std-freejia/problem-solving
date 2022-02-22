/** 명령 프롬프트
 * https://www.acmicpc.net/problem/1032
 * http://boj.kr/f50745fe75c042b19f172019912c61d1
 * */
#include <bits/stdc++.h>
using namespace std;

int n, h, idx;
vector<string> v;
string input, answer;
bool check_flag = true;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> input;
    v.push_back(input);
  }
  int len = v[0].length(); // 문자열 길이 (모두 같다)
  int vsize = v.size();

  for(idx = 0; idx < len; idx++){
    check_flag = true;
    for(h = 0; h < vsize-1; h++) { // 모든 문자열의 인덱스 h자리가 같은지.
      if (v[h][idx] != v[h + 1][idx]) {
        check_flag = false; break;
      }
    }
    check_flag ? answer += v[h][idx] : answer += "?";
  }
  cout << answer;
  return 0;
}