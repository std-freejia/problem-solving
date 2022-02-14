/** 괄호
 https://www.acmicpc.net/problem/9012
 http://boj.kr/ac1a8f71cfbe4c62abbc1aa710778283
 */
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int t;
string input;

bool check(string s){
  stack<char> st;
  for(auto i : s){
    if(i == '(') st.push('(');
    else if(!st.empty() && st.top() == '('){
      st.pop();
    }else return false;
  }

  if(st.empty()) return true;
  else return false;
}
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> t;

  while(t--){
    cin >> input;
    if(check(input)) cout << "YES" << endl;
    else cout << "NO" << endl;
  }

  return 0;
}