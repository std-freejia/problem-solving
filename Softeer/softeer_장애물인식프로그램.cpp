#include <bits/stdc++.h>
using namespace std;

int n; // 지도의 크기
char ch;
char obs_map[26][26];
vector<int> answer;
bool check[26][26];

int nx[4] = {1, -1, 0, 0};
int ny[4] = {0, 0, 1, -1};

bool check_boundary(int x, int y){ // 정상범위인지 확인
  return (x >= 0 && x < n && y >= 0 && y < n);
}

int BFS(int i, int j){
  int cnt = 1;

  queue<pair<int,int>> qu;
  check[i][j] = true;
  qu.push({i, j});

  while(!qu.empty()){
    int cur_x = qu.front().first;
    int cur_y = qu.front().second;
    qu.pop();

    for(int i = 0; i < 4; i++){
      int next_x = nx[i] + cur_x;
      int next_y = ny[i] + cur_y;

      if(!check_boundary(next_x, next_y)) continue; // 정상범위
      if(check[next_x][next_y]) continue; // 이미 방문
      if(obs_map[next_x][next_y] == '0') continue;  // 도로
      else{
        check[next_x][next_y] = true;
        qu.push({next_x, next_y});
        cnt++;
      }
    }
  }
  return cnt;
}
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n; // 지도의 크기
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      cin >> ch;
      obs_map[i][j] = ch;
    }
  } // 입력받기 끝


  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      if(obs_map[i][j] == '1' && !check[i][j]){
        int cnt = BFS(i, j);
        //cout << "cnt:" << cnt << '\n';
        answer.push_back(cnt);
      }
    }
  }

  sort(answer.begin(), answer.end());
  cout << answer.size() << '\n';
  for(auto i : answer) cout << i << '\n';

  return 0;
}