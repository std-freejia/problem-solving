#include <bits/stdc++.h>
using namespace std;

bool checked[202]; // 방문 체크 배열
int node_cnt; // 노드 총 개수

void dfs(int current, vector<vector<int>> &computers){
  checked[current] = true;

  for(int i = 0; i < node_cnt; i++){
    if(!checked[i] && computers[current][i] == 1) // 미방문 && 연결됬다면
      dfs(i, computers);
  }
}

int solution(int n, vector<vector<int>> computers) {
  int answer = 0;
  node_cnt = n; // 컴퓨터 개수 전역변수

  for(int i = 0; i < n; i++){ // 모든 노드에서 탐색 시작
    if(!checked[i]){ // 미방문이라면 탐색 시작
      answer++;
      dfs(i, computers);
    }
  }
  return answer;
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n = 3;
  vector<vector<int>> computers ={{1,1,0}, {1,1,0}, {0,0,1}};
  cout << solution(n, computers);

  return 0;
}
