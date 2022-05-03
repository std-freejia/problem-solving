#include <bits/stdc++.h>
using namespace std;

int D[501][501];

int solution(vector<vector<int>> t) {
  int answer = 0;

  D[0][0] = t[0][0];
  D[1][0] = t[1][0] + D[0][0];
  D[1][1] = t[1][1] + D[0][0];

  int height_t = t.size();

  for(int i = 2; i < height_t; i++){

    for(int j = 0; j <= i; j++){
      if(j == 0) D[i][j] = t[i][j] + D[i-1][j];
      else if(j == i) D[i][j] = t[i][j] + D[i-1][i-1];
      else{
        D[i][j] = t[i][j] + max(D[i-1][j], D[i-1][j-1]);
      }
    }
  }

  for(int i = 0; i < height_t; i++){
    answer = max(answer, D[height_t-1][i]);
  }

  return answer;
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  vector<vector<int>> triangle = {{7}, {3, 8}, {8, 1, 0}, {2, 7, 4, 4}, {4, 5, 2, 6, 5}};
  cout << solution(triangle);

  return 0;
}