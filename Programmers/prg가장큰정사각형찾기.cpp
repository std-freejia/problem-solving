#include <bits/stdc++.h>
using namespace std;

int solution(vector<vector<int>> board)
{
  int answer = board[0][0];
  int h = board.size();
  int w = board[0].size();

  for(int i = 1; i < h; i++){
    for(int j = 1; j < w; j++){
      if(board[i][j] == 1){
        // 오른쪽, 아래, 대각선의 최소값을 구하고, 1을 더한다.
        board[i][j] = 1 + min({board[i-1][j-1], board[i][j-1], board[i-1][j]});
        answer = max(board[i][j], answer);
      }
    }
  }
  return answer * answer;
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  vector<vector<int>> board = {{0,1,1,1}, {1,1,1,1},
                               {1,1,1,1}, {0,0,1,0}};
  cout << solution(board);
  return 0;
}