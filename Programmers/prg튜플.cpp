#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

bool cmp(pair<int,int> &a, pair<int,int> &b){
  return a.second > b.second;
}
vector<int> solution(string s) {
  vector<int> answer;
  string s_num;

  for(char ch : s){

    if(isdigit(ch)) s_num += ch; // 숫자라면, s_num 문자열에 이어붙인다.

    else if(!s_num.empty()){ // 숫자가 아닌게 나오면 벡터에 푸시하고 문자열 초기화
      answer.push_back(stoi(s_num));
      s_num = "";
    }
  }
  map<int,int> tuple_map;
  for(int i = 0; i < answer.size(); i++){
    tuple_map[answer[i]]++;
  }
  answer.clear();

  vector<pair<int,int>> pv(tuple_map.begin(), tuple_map.end());
  sort(pv.begin(), pv.end(), cmp);
  for(int i = 0; i < pv.size(); i++) answer.push_back(pv[i].first);

  return answer;
}