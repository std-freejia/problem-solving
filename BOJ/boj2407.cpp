/** 조합
 * https://www.acmicpc.net/problem/2407
 * http://boj.kr/2d950b098d264f92995a76f1e09ee7fa
*/
#include <bits/stdc++.h>
using namespace std;

int n, m;
string dp[102][102];

string numAdd(string n1, string n2){
  string answer = "";
  int sum = 0;
  int len = max(n1.size(), n2.size());

  for(int i = 0; i < len || sum; i++){ // 일의 자리를 덧셈한다.
    if(n1.size() > i) sum += (n1[i] - '0');
    if(n2.size() > i) sum += (n2[i] - '0');
    answer += ((sum % 10) + '0');
    sum /= 10;
  }

  return answer;
}

string combination(int n, int m){
  if(n == m || m == 0) return "1";

  string &res = dp[n][m];
  if(res != "") return res;

  res = numAdd(combination(n-1, m-1), combination(n-1, m));
  return res;
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  string ans = combination(n, m);
  reverse(ans.begin(), ans.end());
  cout << ans;
  return 0;
}