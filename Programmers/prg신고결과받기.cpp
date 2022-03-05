#include <string>
#include <vector>
#include <unordered_map>
#include <map>
#include <set>

using namespace std;

map<string, int> report_cnt; // 유저별 신고당한 횟수
unordered_map<string, set<string>> report_map; // 유저별 신고한 타 유저 리스트

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
  vector<int> answer;


  for(string s : report){
    int blank = s.find(' ');
    string from = s.substr(0, blank);
    string to = s.substr(blank);

    if(report_map[from].find(to) == report_map[from].end()){
      report_cnt[to]++; // to 가 신고당한 횟수
      report_map[from].insert(to); // from 이 to를 신고함
    }
  }
  for(string s : id_list){
    int res = 0;
    for(string target : report_map[s]){ // 유저 s가 신고한 타겟들
      if(report_cnt[target] >= k) res++; // 타겟이 신고당한 횟수가 k이상이면? res를 증가시킴
    }
    answer.emplace_back(res);
  }
  return answer;
}