#include <bits/stdc++.h>
using namespace std;

int total_cnt;
vector<string> answer;
bool visited[100002];

bool DFS(string current, int used_cnt, vector<vector<string>> &tickets){
  // 종료조건 모든 티켓 사용 여부
  if(used_cnt == total_cnt) return true;

  for(int i = 0; i < tickets.size(); i++){
    // 시작지가 target 이고, 미방문인 티켓을 전부 방문 가능한 후보로 저장한다.
    if(tickets[i][0] == current && visited[i] == false){
      visited[i] = true;
      answer.push_back(tickets[i][1]);
      bool res = DFS(tickets[i][1], used_cnt + 1, tickets);

      if(res) return true;
      visited[i] = false;
    }
  }
  // 갈 곳이 없으면, 가장 최근에 사용한 티켓을 제거
  answer.pop_back();
  return false;

}

vector<string> solution(vector<vector<string>> tickets) {

  total_cnt = tickets.size();

  // 가능한 경로가 2개 이상일 경우 알파벳 순서가 앞서는 경로가 우선
  sort(tickets.begin(), tickets.end());

  answer.push_back("ICN");
  DFS("ICN", 0, tickets); // 항상 ICN에서 시작

  return answer;
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

//  vector<vector<string>> tickets = {{"ICN", "JFK"},
//                                    {"HND", "IAD"}, {"JFK", "HND"}};

  vector<vector<string>> tickets = {{"ICN", "SFO"},{"ICN", "ATL"}, {"SFO", "ATL"},
                                    {"ATL", "ICN"}, {"ATL","SFO"}};

  vector<string> answer = solution(tickets);

  for(auto a : answer){
    cout << a << ' ' ;
  }

  return 0;
}