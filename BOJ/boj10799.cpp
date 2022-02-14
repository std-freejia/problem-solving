/** 쇠막대기
 https://www.acmicpc.net/problem/10799
 http://boj.kr/4fcfe35ad9a14a5898bf22af9c5f25c9
 */
#include <bits/stdc++.h>
using namespace std;

long long answer;
string input;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> input;

  stack<char> st;
  int len = input.length();
  for(int i = 0; i < len; i++){

    if(input[i] == '(') {
      st.push(input['i']);
    }
    else if(input[i-1] == '(' && input[i] == ')'){ // 레이저
      st.pop();
      answer += st.size();
    }else { // 막대의 마지막 꼬다리
      answer++;
      st.pop();
    }
  }

  cout << answer;
  return 0;
}