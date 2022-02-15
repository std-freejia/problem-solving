/** 괄호의 값
 https://www.acmicpc.net/problem/2504
 http://boj.kr/653d92b7d0e34640a19a12605b1c704f
 */
#include <bits/stdc++.h>
using namespace std;

int answer;
string input;
stack<char> st;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> input;
  int temp = 1;

  for(int i = 0; i < input.length(); i++){
    if(input[i] == '('){
      temp *= 2;
      st.push('(');
    }else if(input[i] == '['){
      temp *= 3;
      st.push('[');
    }else if(input[i] == ')' && (st.size() == 0 || st.top() != '(')){// 불가
      answer = 0; break;
    } else if(input[i] == ']' && (st.size() == 0 || st.top() != '[')){ // 불가
      answer = 0; break;
    }else if(input[i] == ')'){
      if(input[i-1] == '(') answer += temp; // 직전이 여는괄호일 때만 더해준다.
      st.pop();
      temp /= 2;
    }else if(input[i] == ']'){
      if(input[i-1] == '[') answer += temp;
      st.pop();
      temp /= 3;
    }
  }

  (st.empty()) ? cout << answer : cout << 0;
  return 0;
}