#include <bits/stdc++.h>
using namespace std;

int solution(string s){
  int answer = 0;
  int len = s.length();
  int i = 0;
  stack<char> st;

  if(s.empty() || len % 2 == 1) return 0;
  while(i < len){
    if(st.empty() || st.top() != s[i]) {
      st.push(s[i]);
    }
    else if(st.top() == s[i]) {
      st.pop();
    }
    i++;
  }
  answer = (st.size() != 0) ? 0 : 1;
  return answer;
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cout << solution("baabaa") << '\n';
  cout << solution("cdcd") << '\n';

  return 0;
}
