/** * 좋은 단어
 https://www.acmicpc.net/problem/3986
 http://boj.kr/47a71e50b62f4dbfbe9dc61d03794a03
 */
#include <bits/stdc++.h>
using namespace std;

int n, answer;
string word;

bool check(string input){
  stack<char> st;

  int slen = input.length();
  if (slen % 2 == 1) return false;

  st.push(input[0]);
  for(int i = 1; i < slen; i++){
    if(!st.empty() && st.top() == input[i]) st.pop();
    else st.push(input[i]);
  }
  if(st.empty()) return true;
  else return false;
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  while(n--){
    cin >> word;
    if (check(word)) answer++;
  }
  cout << answer;
  return 0;
}