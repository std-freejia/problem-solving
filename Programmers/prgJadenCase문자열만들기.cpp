#include <string>
#include <vector>
using namespace std;

string solution(string s) {
  string answer = "";

  answer += toupper(s[0]);
  for(int i = 1; i < s.size(); i++){
    if(s[i-1] == ' '){ // 공백 뒤에 대문자
      answer += toupper(s[i]);
    }else{
      answer += tolower(s[i]);
    }
  }

  return answer;
}