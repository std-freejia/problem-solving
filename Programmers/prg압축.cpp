#include <string>
#include <vector>
#include <map>
using namespace std;

map<string,int> dic; // {단어, 색인 번호}
int num = 1; // 색인 번호

void init_dictionary(){
  char ch = 'A';
  for(; ch <= 'Z'; ch++, num++){
    string st = ""; st += ch;
    dic[st] = num;
  }
}

vector<int> solution(string msg) {
  vector<int> answer;

  init_dictionary();
  int len = msg.length();
  int start_idx = 0, next_idx = start_idx + 1;

  string target = "";
  for(int i = 0; i < len; i++){ // 탐색 시작할 인덱스 i
    target += msg[i]; // 탐색할 문자

    if(dic.find(target) == dic.end()){
      dic[target] = num++; // 사전에 등록

      target = target.substr(0, target.size()-1);
      answer.push_back(dic[target]);
      target = "";
      i--;
    }
  }
  answer.push_back(dic[target]); // 마지막 글자
  return answer;
}