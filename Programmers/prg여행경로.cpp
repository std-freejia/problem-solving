#include <bits/stdc++.h>
using namespace std;

vector<string> routes; // 정답 경로 벡터
bool visit[100002]; // 방문 체크

bool DFS(string start, int cnt, vector<vector<string>> &tickets){

  if(cnt == tickets.size()) return true; // 탐색 끝나면 true

  for(int i = 0; i < tickets.size(); i++){
    if(visit[i] == false && start == tickets[i][0]){ // 미방문이고, 시작점 타겟이 맞으면, 방문하자
      visit[i] = true;
      routes.push_back(tickets[i][1]); // 방문한 도착지를 답 벡터에 푸시
      bool res = DFS(tickets[i][1], cnt+1, tickets);
      if(res) return true;
      visit[i] = false;
    }
  }
  // 갈 곳이 없으면, 가장 최근에 도착한 곳을 제거.
  routes.pop_back();
  return false;
}

vector<string> solution(vector<vector<string>> tickets) {

  sort(tickets.begin(), tickets.end()); // 알파벳 순 앞서는 경로 선택

  routes.push_back("ICN");
  DFS("ICN", 0, tickets); // 시작점 타겟은 "ICN"

  return routes;
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  vector<vector<string>> tickets{{"ICN", "JFK"}, {"HND", "IAD"}, {"JFK", "HND"}};
  vector<string> answer = solution(tickets);
  for(auto a : answer){ cout << a << ' ';}
  return 0;
}


