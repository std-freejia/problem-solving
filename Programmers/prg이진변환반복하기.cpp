#include <bits/stdc++.h>
using namespace std;

vector<int> solution(string s) {
  vector<int> answer(2, 0);

  while(s != "1"){
    string temp = "";

    for(int i = 0; i < s.size(); i++){
      if (s[i] == '0') answer[1]++; // 제거한 0의 개수 세기
      else temp += "1";
    }
    int c = temp.size(); // temp의 길이 c
    string c_st = "";

    while(c > 0){
      c_st += to_string(c % 2);
      c /= 2;
    }
    answer[0]++; // 이진 변환 횟수 카운팅
    reverse(c_st.begin(), c_st.end()); // 이진수를 s에 대입
    s = c_st;
  }
  return answer;
}
