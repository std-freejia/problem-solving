#include <string>
#include <vector>
#include <stack>
using namespace std;

int answer, ssize;

bool check(string s){
  bool res = true;
  stack<char> st;

  for(int i = 0; i < ssize; i++){
    if(s[i] == '{' || s[i] == '(' || s[i] == '['){
      st.push(s[i]);
    }else if(!st.empty()){
      if( (st.top() - s[i] == -1) || (st.top() - s[i] == -2)){
        st.pop();
      }else{
        res = false; break;
      }
    }else if(st.empty()){
      if(s[i] == '}' || s[i] == ')' || s[i] == ']')
        res = false; break;
    }
  }
  if(!st.empty()) res = false;
  return res;
}
int solution(string s) {
  ssize = s.size();
  s += s;

  for(int i = 0; i < ssize; i++){
    string target = s.substr(i, ssize);
    bool result = check(target);
    if(result) answer++;
  }
  return answer;
}