#include <bits/stdc++.h>
using namespace std;

int k, m, n, num, cnt;
string code, user_input;
string answer = "secret";

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> m >> n >> k;

  for(int i = 0; i < m; i++){
    cin >> num;
    code.push_back(num + '0');
  }
  for(int i = 0; i < n; i++){
    cin >> num;
    user_input.push_back(num + '0');
  }

  smatch match;
  while(regex_search(user_input, match, regex(code))){
    user_input = match.suffix();
    cnt++;
  }

  if(cnt == 0) answer = "normal";
  cout << answer;
  return 0;
}