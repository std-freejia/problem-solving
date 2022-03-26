#include <bits/stdc++.h>
using namespace std;

string solution(string number, int k) {

  string answer = "";
  int num_size = number.size();
  int target_len = num_size - k;
  stack<char> st;

  for(int i = 0; i < num_size; i++){
    char ch = number.at(i);
    while(!st.empty() && k > 0){
      if(ch > st.top()){
        st.pop(); k--;
      }
      else break;
    }
    st.push(ch);
  }

  while(st.size() != target_len) st.pop();   // target_len == stack.size()

  while(!st.empty()) {
    answer = st.top() + answer;
    st.pop();
  }
  return answer;
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  string number = "4177252841";
  int k = 4;

  cout << solution(number, k);

  return 0;
}
