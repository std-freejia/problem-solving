/** 균형잡힌 세상
 https://www.acmicpc.net/problem/4949
 http://boj.kr/5dc3c0fefee94db6a5731ed02e110a46
*/
#include "bits/stdc++.h"
using namespace std;

bool check(string &s){
  stack<char> st;
  for(auto i : s){
    if(i == '(' || i == '['){ st.push(i);
    }else if(i == ')'){
      if(st.size() > 0 && st.top() == '(') st.pop();
      else return false;
    }else if(i == ']'){
      if(st.size() > 0 && st.top() == '[') st.pop();
      else return false;
    }
  }

  return st.empty() ? 1 : 0;
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  string input = "";
  while(getline(cin, input)){
    if(input == ".") break;
    (check(input)) ? cout << "yes\n" :  cout << "no\n";
  }
  return 0;
}