/** 뱀과 사다리 게임
 * https://www.acmicpc.net/problem/16928
 * http://boj.kr/c684b274e0ea427b8a943cb4d2cc941a
*/
#include <bits/stdc++.h>
using namespace std;

int n, m, a, b;
int answer = 1e9;
int board[102]; // 게임판
bool visited[102]; // 방문 체크

int bfs(){
    queue<pair<int,int>> qu; // <현재위치, 주사위 던진 횟수>
    qu.push({1, 0});
    visited[1] = true;

    while(!qu.empty()){
      pair<int,int> p = qu.front();
      qu.pop();

      int cur = p.first;
      int cur_cnt = p.second;

      if(cur == 100) {  answer = min(answer, cur_cnt); break; }// 목적지 도착

      for(int i = 1; i <= 6; i++){ // 주사위
        int next_cur = cur + i;
        if(next_cur > 100 || visited[next_cur]) continue; // 방문했거나 범위 초과시 지나감
        visited[next_cur] = true;

        if(board[next_cur] == 0) qu.push({next_cur, cur_cnt + 1});
        else qu.push({board[next_cur], cur_cnt + 1});
      }
    }
    return answer;
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  for(int i = 0; i < n; i++){ // 사다리
    cin >> a >> b; board[a] = b;
  }
  for(int i = 0; i < m; i++){ // 뱀
    cin >> a >> b; board[a] = b;
  }

  cout << bfs();

  return 0;
}
