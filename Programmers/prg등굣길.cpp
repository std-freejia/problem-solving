#include <bits/stdc++.h>
using namespace std;

int D[101][101]; // 최단거리를 저장할 배열
int div_num = 1000000007;

int solution(int m, int n, vector<vector<int>> puddles) {

  for(auto v : puddles){
    D[v[1]][v[0]] = -1; // 물웅덩이를 -1로 초기화
  }
  D[1][1] = 1;

  for(int i = 1; i <= n; i++){ // n: 행
    for(int j = 1; j <=m; j++){ // m: 열
      if(D[i][j] == -1) continue;
      int temp_a = 0, temp_b = 0;

      if(D[i-1][j] != -1) temp_a = D[i-1][j];
      if(D[i][j-1] != -1) temp_b = D[i][j-1];

      D[i][j] += (temp_a + temp_b) % div_num;
    }
  }

  return D[n][m];
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int m = 4, n = 3;
  vector<vector<int>> puddles = {{2, 2}};

  cout << solution(m, n, puddles);
  return 0;
}