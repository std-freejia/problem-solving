/** 바이러스
 https://www.acmicpc.net/problem/2606
 http://boj.kr/0eb4f681c1a549cc83a358933dd9a827
 */
#include <bits/stdc++.h>
using namespace std;

int n, m, i, j;
vector<int> v[102]; // 인접리스트
bool visited[102]; // 방문체크
int cnt; // 1과 인접 개수

void dfs(int x){
  visited[x] = true; //방문
  for(int i = 0; i < v[x].size(); i++){
    int nextnode = v[x][i];
    if(!visited[nextnode]){
      dfs(nextnode);
      cnt++;
    }
  }
}
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;

  while(m--){
    cin >> i >> j;
    v[i].push_back(j);
    v[j].push_back(i);
  }
  dfs(1); // 1번은 이미 걸렸고, 1번 때문에 바이러스 걸리는 컴퓨터의 개수
  cout << cnt;
  return 0;
}